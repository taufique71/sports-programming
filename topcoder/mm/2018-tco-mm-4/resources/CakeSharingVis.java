import java.awt.*;
import java.awt.event.*;
import java.awt.image.*;
import java.awt.geom.*;
import java.io.*;
import java.security.*;
import java.util.*;
import java.util.List;
import javax.imageio.*;
import javax.swing.*;

class Point {
    public int x, y;
    public Point(int px, int py) {
        x = px;
        y = py;
    }
    public boolean equals(Point p) {
        return x == p.x && y == p.y;
    }
    public String toString() {
        return "(" + x + "," + y + ")";
    }
}

class Cut {
    public Point start, end;
    public Cut(Point s, Point e) {
        start = s;
        end = e;
    }
    public Cut(int x1, int y1, int x2, int y2) {
        start = new Point(x1, y1);
        end = new Point(x2, y2);
    }
    public boolean equals(Cut obj) {
        // same cut can be done in both directions
        return start.equals(obj.start) && end.equals(obj.end) || start.equals(obj.end) && end.equals(obj.start);
    }
    public String toString() {
        return start + " - " + end;
    }
}

public class CakeSharingVis {
    static int minS = 10, maxS = 80; 
    static int minN = 5;

    static final int invalidScore = -1;

    int H, W, N, NR;
    char[][] roses;                         // R is a rose, . is an empty square of a cake, D is a rose destroyed
    volatile List<ArrayList<Point>> pieces; // pieces produced so far
    volatile List<Double> areas;            // areas of the pieces
    volatile List<Integer> rosesInside;     // numbers of roses inside pieces
    volatile List<Point> centers;           // visualization only: store coordinates of piece centers
    volatile List<Polygon> polygons;        // visualization only: store polygons to fill pieces with colors
    volatile List<Cut> cuts;                // visualization only: list of cuts done
    volatile List<Cut> redos;               // visualization only: list of redo cuts
    int[][] rosesPiecesIdx;                 // visualization only: roses pieces index
    final Object lock = new Object();       // to avoid concurrence issues
    double score = 0;
    // -----------------------------------------
    boolean isInside(Point p) {
        return (p.y >= 0 && p.y <= H && p.x >= 0 && p.x <= W);
    }
    // -----------------------------------------
    int isOnPieceEdge(ArrayList<Point> piece, Point p) {
        // return is the index of the point p in the piece or -1 if it does not belong
        for (int i = 0; i < piece.size(); ++i)
            if (piece.get(i).equals(p))
                return i;
        return -1;
    }
    // -----------------------------------------
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    // -----------------------------------------
    void addPointsOnCut(ArrayList<Point> piece, int loc, Point p1, Point p2) {
        // adds all integer points on a cut from p1 to p2 (not inclusive) to piece starting at location loc
        int dx = p2.x - p1.x, dy = p2.y - p1.y;
        int g = Math.abs(gcd(dx, dy));
        if (g == 1)
            return;
        for (int i = 1; i < g; ++i)
            piece.add(loc + i - 1, new Point(p1.x + dx / g * i, p1.y + dy / g * i));
    }
    // -----------------------------------------
    boolean isRoseInsidePiece(ArrayList<Point> piece, Point p) {
        // in this code path the coordinates of piece vertices have to be doubled
        // (the coordinate of the rose is already 2 * (row and col index of the cell in which it is) + 1)
        boolean inside = false;
        for (int i = 0; i < piece.size() - 1; ++i) {
            Point p1 = piece.get(i), p2 = piece.get(i+1);
            int dy = Math.abs(p1.y - p2.y);
            if ((2 * p1.y > p.y) != (2 * p2.y > p.y) && 
                (p.x - 2 * p1.x) * dy < (p2.x - p1.x) * (p.y - 2 * p1.y) * dy / (p2.y - p1.y) )
                inside = !inside;
        }
        return inside;
    }
    // -----------------------------------------
    int updateRosesInsidePiece(ArrayList<Point> piece, int idx) {
        int n = 0;
        for (int r = 0; r < H; ++r)
        for (int c = 0; c < W; ++c) {
            if (roses[r][c] != 'R')
                continue;
            if (isRoseInsidePiece(piece, new Point(2 * c + 1, 2 * r + 1))) {
            	if (vis) 
            		rosesPiecesIdx[r][c] = idx;
                n++;
            }
        }
        return n;
    }
    // -----------------------------------------
    double getPieceArea(ArrayList<Point> piece) {
        double a = 0;
        for (int i = 0; i < piece.size() - 1; ++i) {
            Point p1 = piece.get(i), p2 = piece.get(i+1);
            a += (p2.x - p1.x) * (p1.y + p2.y);
        }
        return Math.abs(a) / 2.0;
    }
    // -----------------------------------------
    String generate(String seedStr) {
      try {
        // generate test case
        SecureRandom r1 = SecureRandom.getInstance("SHA1PRNG"); 
        long seed = Long.parseLong(seedStr);
        r1.setSeed(seed);
        H = r1.nextInt(maxS - minS + 1) + minS;
        W = r1.nextInt(maxS - minS + 1) + minS;
        // the max number of pieces into which an H x W cake can be cut is 2*(W+H-1)
        int maxN = 2 * (W + H);
        N = r1.nextInt(maxN - minN + 1) + minN;
        int pRose = r1.nextInt(81) + 10;
        if (seed == 1) {
            W = H = minS;
            N = minN;
            pRose = 7;
        }
        else if (seed == 2) {
            W = H = (minS + maxS) / 2;
            N = 10;
        }
        else if (seed == 3) {
            W = H = maxS;
            N = 2 * (W + H); //FIXED, so seed 3 has pieces = maxPieces
        }

        // generate the board
        roses = new char[H][W];
        NR = 0;

        for (int r = 0; r < H; ++r)
        for (int c = 0; c < W; ++c) {
            int t = r1.nextInt(100);
            roses[r][c] = (t < pRose ? 'R' : '.');
            if (roses[r][c] == 'R')
                NR++;
        }

        StringBuffer sb = new StringBuffer();
        sb.append("H = ").append(H).append('\n');
        sb.append("W = ").append(W).append('\n');
        sb.append("Number of pieces N = ").append(N).append('\n');
        sb.append("Probability of a rose = ").append(pRose).append('\n');
        sb.append("Number of roses = ").append(NR).append('\n');
        for (int i = 0; i < H; ++i) {
            sb.append(new String(roses[i])).append('\n');
        }
        return sb.toString();
      }
      catch (Exception e) {
        addFatalError("An exception occurred while generating test case.");
        e.printStackTrace(); 
        return "";
      }
    }
    // -----------------------------------------
    String toString(ArrayList<Point> piece) {
        StringBuffer sb = new StringBuffer();
        for (int i = 0; i < piece.size(); ++i) {
            if (i > 0)
                sb.append(" ");
            sb.append(piece.get(i));
        }
        return sb.toString();
    }
    // -----------------------------------------
    String makeCut(Point p1, Point p2) {
    synchronized (lock) {
        // the logic of making a cut
        if (p1.equals(p2)) {
            return "The cut must have non-zero length.";
        }
        if (!isInside(p1) || !isInside(p2)) {
            return "The cut can not start or end outside the cake.";
        }
        // if a cut duplicates part of an edge or a previous cut, we'll get a zero-area piece - prohibit explicitly later

        // check that there exists a piece to which both ends of the cut belong
        int ind = -1, i1 = -1, i2 = -1;     // store the index of the piece and the indices of points within the piece
        for (int i = 0; i < pieces.size(); ++i) {
            ArrayList<Point> piece = pieces.get(i);
            i1 = isOnPieceEdge(piece, p1);
            if (i1 == -1)
                continue;
            i2 = isOnPieceEdge(piece, p2);
            if (i2 == -1) {
                i1 = -1;
                continue;
            }
            ind = i;
            break;
        }
        if (ind == -1) {
            return "The cut must divide one piece in two pieces.";
        }

        // to make sure that the points are always listed in the same direction, 
        // swap the cut endpoints if they are in reverse order (so that p1 is always found first)
        if (i1 > i2) {
            int t = i2;
            i2 = i1;
            i1 = t;
            Point tmp = p2;
            p2 = p1;
            p1 = tmp;
        }

        // make the cut: split the piece #ind in two, 
        // points 0..i1 and i2..last stay in the old piece together (i1 = p1 and i2 = p2), plus points between p1 and p2
        // points i1..i2 form a new piece, plus points between p2 and p1 (same extra points in reverse order)
        ArrayList<Point> pold = pieces.get(ind);
        ArrayList<Point> pnew = new ArrayList<Point>();
        for (int i = i1; i <= i2; ++i)
            pnew.add(pold.get(i));
        addPointsOnCut(pnew, pnew.size(), p2, p1);
        pnew.add(p1);       // to close the loop

        double anew = getPieceArea(pnew);
        if (anew < 0.25)
            return "The pieces produced by the cut must have non-zero area.";

        // update old piece: erase extra points from the old piece (keep p1 and p2) and insert points between p1 and p2 in their place
        ArrayList<Point> pold_updated = new ArrayList<Point>();
        for (int i = 0; i <= i1; ++i)
            pold_updated.add(pold.get(i));
        addPointsOnCut(pold_updated, pold_updated.size(), p1, p2);
        for (int i = i2; i < pold.size(); ++i)
            pold_updated.add(pold.get(i));
        double aold = getPieceArea(pold_updated);
        if (aold < 0.25)
            return "The pieces produced by the cut must have non-zero area.";

        pieces.add(pnew);
        areas.add(anew);
        if (vis) {
        	centers.add(getPieceCenter(pnew));
        	polygons.add(getPiecePolygon(pnew));
        }

        pieces.set(ind, pold_updated);
        areas.set(ind, aold);
        if (vis) {
        	centers.set(ind, getPieceCenter(pold_updated));
        	polygons.set(ind, getPiecePolygon(pold_updated));
        }

        Cut c = new Cut(p1, p2);
        cuts.add(c);

        if (debug) {
            System.out.println("Pieces after cut " + c + ":");
            for (int i = 0; i < pieces.size(); ++i)
                System.out.println(toString(pieces.get(i)) + ", area " + areas.get(i));
            System.out.println();
        }

        // destroy any roses on the cut
        if (p1.x != p2.x && p1.y != p2.y) {
            int xs, xe, ys, ye;
            if (p1.x < p2.x) {
                xs = p1.x;
                ys = p1.y;
                xe = p2.x;
                ye = p2.y;
            } else {
                xs = p2.x;
                ys = p2.y;
                xe = p1.x;
                ye = p1.y;
            }
            int dx = xe - xs, dy = ye - ys;
            for (int x = xs; x < xe; ++x) {
                int y = ys + (((2 * (x - xs) + 1) * dy) / dx - 1) / 2;
                if ((2 * (y-ys) + 1) * dx == (2 * (x-xs) + 1) * dy && roses[y][x] == 'R') {
                    roses[y][x] = 'D';
                    NR--;
                    if (debug) {
                        System.out.println("Destroyed a rose at (" + y + ", " + x + ")");
                    }
                }
            }
        }

        // update roses count (after destroyed roses are updated)
        rosesInside.set(ind, updateRosesInsidePiece(pold_updated, ind));
        rosesInside.add(updateRosesInsidePiece(pnew,rosesInside.size()));
        getScore();
    }
        return "";
    }
    // -----------------------------------------
    void initBoard() {
        // we start with one rectangular piece (the whole cake)
        pieces = new ArrayList<ArrayList<Point>>();
        areas = new ArrayList<Double>();
        rosesInside = new ArrayList<Integer>();

        for (int y = 0; y < H; ++y) 
            for (int x = 0; x < W; ++x) 
                if (roses[y][x] == 'D') {
                    roses[y][x] = 'R';
                    NR++;
                }
        
        ArrayList<Point> p0 = new ArrayList<Point>();
        Point v1 = new Point(0, 0), v2 = new Point(W, 0), v3 = new Point(W, H), v4 = new Point(0, H);
        p0.add(v1);
        addPointsOnCut(p0, p0.size(), v1, v2);
        p0.add(v2);
        addPointsOnCut(p0, p0.size(), v2, v3);
        p0.add(v3);
        addPointsOnCut(p0, p0.size(), v3, v4);
        p0.add(v4);
        addPointsOnCut(p0, p0.size(), v4, v1);
        p0.add(v1);
        pieces.add(p0);
        areas.add(getPieceArea(p0));
        rosesInside.add(NR);
        cuts = new ArrayList<Cut>();
        
        if (vis) {
            centers = new ArrayList<Point>();
            centers.add(getPieceCenter(p0));
            polygons = new ArrayList<Polygon>();
            polygons.add(getPiecePolygon(p0));
            rosesPiecesIdx =  new int[H][W];
        }
        getScore();
    }
    // -----------------------------------------
    double getScore() {
        score = 0;
        if (pieces.size() == 1)
            return score;
        double avgArea = H * W * 1.0 / pieces.size();
        double stdDevArea = 0;
        for (int i = 0; i < pieces.size(); ++i)
            stdDevArea += Math.pow(avgArea - areas.get(i), 2);
        stdDevArea = Math.sqrt(stdDevArea / pieces.size()); //FIXED StdDev
        double avgRoses = NR * 1.0 / pieces.size();
        double stdDevRoses = 0;
        for (int i = 0; i < pieces.size(); ++i)
            stdDevRoses += Math.pow(avgRoses - rosesInside.get(i), 2);
        stdDevRoses = Math.sqrt(stdDevRoses / pieces.size()); //FIXED StdDev
        score = (1.0 + stdDevArea) * (1.0 + stdDevRoses);
        return score;
    }
    // -----------------------------------------
    public double runTest(String seed) {
      try {
        String test = generate(seed);
        if (debug)
            System.out.println(test);

        redos = new ArrayList<Cut>();

        if (vis) {
            jf.setVisible(true);
            Insets frameInsets = jf.getInsets();
            int fw = frameInsets.left + frameInsets.right + 8;
            int fh = frameInsets.top + frameInsets.bottom + 8;
            Toolkit toolkit = Toolkit.getDefaultToolkit();
            Dimension screenSize = toolkit.getScreenSize();
            Insets screenInsets = toolkit.getScreenInsets(jf.getGraphicsConfiguration());
            screenSize.width -= screenInsets.left + screenInsets.right;
            screenSize.height -= screenInsets.top + screenInsets.bottom;
            res = Math.max(800, Math.min(screenSize.width, screenSize.height)) / 100;
            if (SZ == 0) {
                SZ = (int)Math.min((screenSize.width - fw - 120) / (W + 0.5), (screenSize.height - fh) / (H + 1));
                if (!plain && SZ < 20) plain = true;
            }
            Dimension dim = v.getVisDimension();
            v.setPreferredSize(dim);
            jf.setSize(Math.min(dim.width + fw, screenSize.width), Math.min(dim.height + fh, screenSize.height));
            manualReady = false;
            //ADDED: Piece's colors 
            pieceColors = new Color[N];
            roseColors = new Color[N];
            Random rnd = new Random(Long.parseLong(seed));
			for (int i = 0; i < N; i++) {
				float h = i < 14 ? (i * 5) % 14 / 14f : rnd.nextFloat();
				float s = i < 14 ? 0.1f : rnd.nextFloat() * 0.1f + 0.1f;
				float b = i < 14 ? 1f : rnd.nextFloat() * 0.1f + 0.9f;
				pieceColors[i] = new Color(Color.HSBtoRGB(h, s, b));
				roseColors[i] = new Color(Color.HSBtoRGB(h, s + 0.2f, b - 0.1f));
			}
        }
        initBoard();
        if (vis) 
            draw();

        if (proc != null) {
            // call the solution
            String[] rosesArg = new String[H];
            for (int i = 0; i < H; ++i) {
                rosesArg[i] = new String(roses[i]);
            }

            String[] cutsRet;
            try {
            	cutsRet = cut(rosesArg, N);
            } catch (Exception e) {
                addFatalError("Failed to get result from cut.");
                return invalidScore;
            }

            // check the return and score it
            if (cutsRet == null) {
                addFatalError("Your return contained invalid number of elements.");
                return invalidScore;
            }
            // number of cuts must equal number of pieces - 1
            if (cutsRet.length != N-1) {
                addFatalError("Your return must contain exactly " + (N-1) + " elements, and it contains " + cutsRet.length + ".");
                return invalidScore;
            }

            // parse each cut and do it
            // pure manual mode returns 0 cuts to process, because they will be done by the player
            for (int i = 0; i < cutsRet.length; ++i) {
                // cut format is "X1 Y1 X2 Y2"
                // check return formatting
                String[] s = cutsRet[i].split(" ");
                if (s.length != 4) {
                    addFatalError("Cut " + i + ": Each element of your return must be formatted as \"X1 Y1 X2 Y2\"");
                    return invalidScore;
                }
                int X1, Y1, X2, Y2;
                try {
                    X1 = Integer.parseInt(s[0]);
                    Y1 = Integer.parseInt(s[1]);
                    X2 = Integer.parseInt(s[2]);
                    Y2 = Integer.parseInt(s[3]);
                }
                catch (Exception e) {
                    addFatalError("Cut " + i + ": all elements in each element of your return must be integers.");
                    return invalidScore;
                }

                // try to do the cut
                Point p1 = new Point(X1, Y1), p2 = new Point(X2, Y2);
                String errmes = makeCut(p1, p2);
                if (!errmes.equals("")) {
                    addFatalError("Cut " + i + ": " + errmes);
                    return invalidScore;
                }
            }

            if (vis)
                draw();
        }

        if (manual) {
            // let player know that we're waiting for their input
            addFatalError("Manual play on");

            // wait till player finishes (possibly on top of automated return)
            while (!manualReady)
            {   try { Thread.sleep(50);}
                catch (Exception e) { e.printStackTrace(); } 
            }
        }

        if (pieces.size() != N) {
            addFatalError("You must cut the cake into exactly " + N + " pieces.");
            return invalidScore;
        }
        return getScore();
      }
      catch (Exception e) { 
        addFatalError("An exception occurred while trying to get your program's results.");
        e.printStackTrace(); 
        return invalidScore;
      }
    }
// ------------- visualization part ------------
    static String seed;
    JFrame jf;
    Vis v;
    static String exec;
    static boolean vis, manual, debug, plain, save, showColors, showPoints, showValues;
    static Process proc; 
    InputStream is;
    OutputStream os;
    BufferedReader br;
    static int SZ, res;
    volatile boolean manualReady;
    volatile Point pStart, pMoving;
    volatile Color[] pieceColors, roseColors;
    // -----------------------------------------
    String[] cut(String[] roses, int NP) throws IOException {
        StringBuffer sb = new StringBuffer();
        sb.append(roses.length).append("\n");
        for (int i = 0; i < roses.length; ++i) {
            sb.append(roses[i]).append("\n");
        }
        sb.append(NP).append("\n");
        os.write(sb.toString().getBytes());
        os.flush();

        // and get the return value
        int N = Integer.parseInt(br.readLine());
        String[] ret = new String[N];
        for (int i = 0; i < N; i++)
            ret[i] = br.readLine();
        return ret;
    }
    // -----------------------------------------
    void draw() {
        if (!vis) return;
        v.repaint();
    }
    // -----------------------------------------
    //ADDED: Improved piece center finding 
    Point getPieceCenter(ArrayList<Point> piece) {
    	List<Point> pts = convexHull(piece);
        int avgX = 0, avgY = 0, np = 0;
        for (int i = 0; i < pts.size(); ++i) { 
            avgX += pts.get(i).x;
            avgY += pts.get(i).y;
            np++;
        }
        return new Point(avgX * SZ / np, avgY * SZ / np);
    }
    // -----------------------------------------
    //ADDED: Polygon that contains piece 
    Polygon getPiecePolygon(ArrayList<Point> piece) {
    	List<Point> pts = convexHull(piece);
    	int[] xp = new int[pts.size()];
    	int[] yp = new int[pts.size()];
        for (int i = 0; i < pts.size(); ++i) { 
            xp[i] = pts.get(i).x * SZ;
            yp[i] = pts.get(i).y * SZ;
        }
        return new Polygon(xp, yp, xp.length);
    }
    // -----------------------------------------
	List<Point> convexHull(List<Point> p) {
		if (p == null) return null;
		if (p.size() < 3) return null;
		Point base = p.get(0);
		for (Point curr : p) {
			if (curr.y < base.y || (curr.y == base.y && curr.x > base.x)) {
				base = curr;
			}
		}
		List<Point> hull = new ArrayList<Point>();
		hull.add(base);
		double prevAng = -1;
		while (true) {
			Point next = null;
			double ang = Math.PI * 3;
			Point last = hull.get(hull.size() - 1);
			for (Point curr : p) {
				if (curr.equals(last)) continue;
				double ca = Math.atan2(curr.y - last.y, curr.x - last.x);
				if (ca < 0) ca += Math.PI * 2;
				if (ca <= ang && ca >= prevAng) {
					ang = ca;
					next = curr;
				}
			}
			prevAng = ang;
			if (next == null || next.equals(base)) break;
			hull.add(next);
		}
		return hull;
	}

    // -----------------------------------------
    boolean isValidEndPoint(Point endPoint) {
        for (int i = 0; i < pieces.size(); ++i) {
            ArrayList<Point> piece = pieces.get(i);
            for (int j = 0; j < piece.size() - 1; ++j) {
                Point p = piece.get(j);
                if (p.equals(endPoint)) return true;
            }
        }
        return false;
    }
    
    // -----------------------------------------
    public class Vis extends JPanel implements MouseListener, WindowListener, MouseMotionListener {
        public void paint(Graphics g) {
            super.paint(g);
            Dimension dim = getVisDimension();
            BufferedImage bi = new BufferedImage(dim.width,dim.height,BufferedImage.TYPE_INT_RGB);
            Graphics2D g2 = (Graphics2D)bi.getGraphics();
            g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
            // background
            g2.setColor(new Color(0xDDDDDD));
            g2.fillRect(0,0,dim.width,dim.height);
            // add a border of SZ/2
            g2.translate(SZ/2, SZ/2);
            // board
            g2.setColor(Color.WHITE);
            g2.fillRect(0,0,W*SZ,H*SZ);
            g2.setBackground(Color.WHITE);

            synchronized (lock) {
            	//Colored pieces
            	if (showColors && !plain) {
                    for (int i = 0; i < pieces.size(); ++i) {
                    	Polygon poly = polygons.get(i);
                    	g2.setColor(pieceColors[i]);
                    	g2.fillPolygon(poly);
                    }
            	}
            	
                //Paint background of cells with roses
                if (showColors && plain) {
                    Color colorRose = new Color(230, 250, 230);
                    Color colorDestroyed = new Color(250, 230, 230);
                    for (int i = 0; i < H; i++)
                    for (int j = 0; j < W; j++)
                        if (roses[i][j] != '.') {
                            int xc = j * SZ;
                            int yc = i * SZ;
                            g2.setColor(roses[i][j] == 'R' ? colorRose : colorDestroyed);
                            g2.fillRect(xc + 1, yc + 1, SZ - 1, SZ - 1);
                        }
                }

                // lines between cells
                g2.setStroke(new BasicStroke(1f));
                g2.setColor(Color.LIGHT_GRAY);
                for (int i = 1; i < H; i++)
                    g2.drawLine(0,i*SZ,W*SZ,i*SZ);
                for (int i = 1; i < W; i++)
                    g2.drawLine(i*SZ,0,i*SZ,H*SZ);
    
                if (showPoints) {
                    // highlight valid end points of cuts
                    int endPointSize = Math.min(Math.max(4, res * 2 / 3), SZ / 2);
                    g2.setStroke(new BasicStroke(1f));
                    g2.setColor(Color.BLUE);
                    for (int i = 0; i < pieces.size(); ++i) {
                        ArrayList<Point> piece = pieces.get(i);
                        for (int j = 0; j < piece.size() - 1; ++j) {
                            Point p = piece.get(j);
                            if (pStart != null && p.equals(pStart)) 
                                g2.fillOval(p.x * SZ - endPointSize/2, p.y * SZ - endPointSize/2, endPointSize, endPointSize);
                            else 
                                g2.drawOval(p.x * SZ - endPointSize/2, p.y * SZ - endPointSize/2, endPointSize, endPointSize);
                        }
                    }
                }
    
                // draw destroyed and intact roses
                g2.setStroke(new BasicStroke(SZ > 50 ? 2f : 1f));
                Color colorDestroyed = new Color(240, 240, 240);
                for (int i = 0; i < H; i++)
                for (int j = 0; j < W; j++)
                    if (roses[i][j] != '.') {
                        int xc = j * SZ + SZ / 2;
                        int yc = i * SZ + SZ / 2;
                        int rs = Math.max(4, SZ / 5);
                        if (plain) {
                            g2.setColor(roses[i][j] == 'R' ? Color.BLACK : Color.LIGHT_GRAY);
                            g2.fillOval(xc - rs / 2, yc -rs / 2, rs, rs);
                        } else {
                            if (showColors) {
                                g2.setColor(roses[i][j] == 'R' ? roseColors[rosesPiecesIdx[i][j]] : colorDestroyed);
                                g2.fillOval(xc - rs / 2 - rs, yc - rs / 2, rs, rs);
                                g2.fillOval(xc - rs / 2 , yc - rs / 2- rs, rs, rs);
                                g2.fillOval(xc - rs / 2 + rs, yc - rs / 2, rs, rs);
                                g2.fillOval(xc - rs / 2 , yc - rs / 2+rs, rs, rs);
                                g2.fillOval(xc - rs / 2, yc - rs / 2, rs, rs);
                            }
                            g2.setColor(roses[i][j] == 'R' ? Color.BLACK : Color.LIGHT_GRAY);
                            g2.drawOval(xc - rs / 2 - rs, yc - rs / 2, rs, rs);
                            g2.drawOval(xc - rs / 2 , yc - rs / 2- rs, rs, rs);
                            g2.drawOval(xc - rs / 2 + rs, yc - rs / 2, rs, rs);
                            g2.drawOval(xc - rs / 2 , yc - rs / 2+rs, rs, rs);
                            g2.drawOval(xc - rs / 2, yc - rs / 2, rs, rs);
                            g2.fillOval(xc - rs / 4, yc - rs / 4, rs / 2, rs / 2);
                        }
                    }

                // draw cuts
                g2.setStroke(new BasicStroke(2f));
                g2.setColor(Color.BLACK);
                g2.drawLine(0, 0, W * SZ, 0);
                g2.drawLine(0, H * SZ, W * SZ, H * SZ);
                g2.drawLine(W * SZ, 0, W * SZ, H * SZ);
                g2.drawLine(0, 0, 0, H * SZ);
                for (int i = 0; i < cuts.size(); ++i) {
                    Cut c = cuts.get(i);
                    g2.drawLine(c.start.x * SZ, c.start.y * SZ, c.end.x * SZ, c.end.y * SZ);
                }
    
                // on each piece, draw its area and number of roses
                if (showValues) {
	                g2.setFont(new Font("Arial",Font.BOLD,res + 1));
	                g2.setColor(new Color(0x0044DD));
	                for (int i = 0; i < pieces.size(); ++i) {
	                    Point center = centers.get(i);
	                    drawString(g2,String.format("%.1f", areas.get(i)),center.x-10,center.y-res*2/3,20,10,0,true);
	                    drawString(g2,String.format("%d", rosesInside.get(i)),center.x-10,center.y+res/2,20,10,0,true);
	                }
                }
                
                if (pStart != null && pMoving != null) {
                    g2.setColor(new Color(0, 0, 255, 100));
                    g2.drawLine(pStart.x * SZ, pStart.y * SZ, pMoving.x, pMoving.y);
                }
    
                // "buttons" to control visualization options
                g2.setFont(new Font("Arial",Font.BOLD,13));
                g2.setStroke(new BasicStroke(1f));
                g2.setColor(Color.BLACK);
                int xText = SZ * W + 10;
                int wText = 100;
                int yText = 10;
                int hButton = 30;
                int hText = 20;
                int vGap = 10;
    
                if (manualReady) 
                    g2.clearRect(xText,yText,wText,hButton);
                drawString(g2,"READY",xText,yText,wText,hButton,0);
                g2.drawRect(xText,yText,wText,hButton);
                yText += hButton + vGap;
    
                if (plain) 
                    g2.clearRect(xText,yText,wText,hButton);
                drawString(g2,"PLAIN",xText,yText,wText,hButton,0);
                g2.drawRect(xText,yText,wText,hButton);
                yText += hButton + vGap;

                if (showPoints) 
                    g2.clearRect(xText,yText,wText,hButton);
                drawString(g2,"POINTS",xText,yText,wText,hButton,0);
                g2.drawRect(xText,yText,wText,hButton);
                yText += hButton + vGap;

                if (showColors) 
                    g2.clearRect(xText,yText,wText,hButton);
                drawString(g2,"COLOR",xText,yText,wText,hButton,0);
                g2.drawRect(xText,yText,wText,hButton);
                yText += hButton + vGap;

                if (showValues) 
                    g2.clearRect(xText,yText,wText,hButton);
                drawString(g2,"VALUES",xText,yText,wText,hButton,0);
                g2.drawRect(xText,yText,wText,hButton);
                yText += hButton + vGap;

                g2.setColor(!manual || manualReady || cuts.isEmpty() ? Color.LIGHT_GRAY : Color.BLACK);
                drawString(g2,"UNDO",xText,yText,wText,hButton,0);
                g2.drawRect(xText,yText,wText,hButton);
                yText += hButton + vGap;
    
                g2.setColor(!manual || manualReady || redos.isEmpty() ? Color.LIGHT_GRAY : Color.BLACK);
                drawString(g2,"REDO",xText,yText,wText,hButton,0);
                g2.drawRect(xText,yText,wText,hButton);
                yText += hButton + vGap;
    
                g2.setColor(!manual || manualReady || cuts.isEmpty() ? Color.LIGHT_GRAY : Color.BLACK);
                drawString(g2,"CLEAR",xText,yText,wText,hButton,0);
                g2.drawRect(xText,yText,wText,hButton);
                yText += hButton + vGap;
                
                // current score
                g2.setColor(Color.BLACK);
                yText += hText;
                drawString(g2,"SCORE",xText,yText,wText,hText,0);
                yText += hText;
                if (pieces.size() != N)
                    g2.setColor(Color.RED);
                drawString(g2,String.format("%.3f", score),xText,yText,wText,hText,0);
                yText += hText * 2;
    
                // current / total number of pieces 
                g2.setColor(Color.BLACK);
                drawString(g2,"PIECES",xText,yText,wText,hText,0);
                yText += hText;
                drawString(g2,pieces.size() + " / " + N,xText,yText,wText,hText,0);
                yText += hText * 2;
            }            
            if (save) {
                try {
                    ImageIO.write(bi,"png", new File(seed + ".png"));
                } catch (Exception e) { e.printStackTrace(); }
            }

            g.drawImage(bi,0,0,null);
        }
        // -------------------------------------
        void drawString(Graphics2D g2, String text, int x, int y, int w, int h, int align) {
        	drawString(g2, text, x, y, w, h, align, false);
        }
        // -------------------------------------
        void drawString(Graphics2D g2, String text, int x, int y, int w, int h, int align, boolean clear) {
            FontMetrics metrics = g2.getFontMetrics();
            Rectangle2D rect = metrics.getStringBounds(text, g2);
            int th = (int)(rect.getHeight());
            int tw  = (int)(rect.getWidth());
            if (align == 0) x = x + (w - tw) / 2;
            else if (align > 0) x = (x + w) - tw;
            if (clear) {
            	Color c = g2.getColor();
            	g2.setColor(new Color(255,255,255,120));
				g2.fillRect(x - 1, y - th / 3 - 1, tw + 2, th + 2);
            	g2.setColor(c);
            }
            y = y + (h - th) / 2 + metrics.getAscent();
            g2.drawString(text, x, y);
        }
        // -------------------------------------
        public Vis() {
            addMouseListener(this);
            addMouseMotionListener(this);
            jf.addWindowListener(this);
        }
        // -------------------------------------
        public Dimension getVisDimension() {
            return new Dimension(W * SZ + SZ / 2 + 126, Math.max((H+1) * SZ + 1, 550));
        }
        // -------------------------------------
        // WindowListener
        public void windowClosing(WindowEvent e){ 
            if(proc != null)
                try { proc.destroy(); } 
                catch (Exception ex) { ex.printStackTrace(); }
            System.exit(0); 
        }
        public void windowActivated(WindowEvent e) { }
        public void windowDeactivated(WindowEvent e) { }
        public void windowOpened(WindowEvent e) { }
        public void windowClosed(WindowEvent e) { }
        public void windowIconified(WindowEvent e) { }
        public void windowDeiconified(WindowEvent e) { }
        // -------------------------------------
        // MouseListener
        public void mousePressed(MouseEvent e) {
            int x = e.getX() - SZ/2 - SZ * W - 10, y = e.getY() - 10 - SZ/2;

            //Find out if a button was clicked 
            int butIdx = y / 40;
            if (x < 0 || x > 100 || y < 0 || y%40 > 30) butIdx = -1;
            
            // Treat "plain" button
            if (butIdx == 1) {
                plain = !plain;
                repaint();
                return;
            }

            //Show points
            if (butIdx == 2) {
                showPoints = !showPoints;
                repaint();
                return;
            }

            //Show colors
            if (butIdx == 3) {
                showColors = !showColors;
                repaint();
                return;
            }

            //Show values
            if (butIdx == 4) {
                showValues = !showValues;
                repaint();
                return;
            }

            // for manual play
            if (!manual || manualReady) return;

            // "ready" button submits current state of the board
            if (butIdx == 0) {
                manualReady = true;
                repaint();
                return;
            }

            // "undo" button removes the last cut, save it for redoing
            if (butIdx == 5) {
                if (cuts.isEmpty()) return;
                redos.add(0,cuts.remove(cuts.size()-1));
                List<Cut> currentCuts = new ArrayList<Cut>(cuts);
                initBoard();
                for(Cut cut : currentCuts) {
                    makeCut(cut.start, cut.end);
                }
                repaint();
                return;
            }

            // "redo" button add a previously "undoed" cut
            if (butIdx == 6) {
                if (redos.isEmpty()) return;
                Cut cut = redos.remove(0);
                makeCut(cut.start, cut.end);
                repaint();
                return;
            }
            
            // "clear" button removes all cuts, saving them for redoing
            if (butIdx == 7) {
                if (cuts.isEmpty()) return;
                redos.addAll(0,cuts);
                initBoard();
                repaint();
                return;
            }

            // regular click starts or ends a cut
            int yint = e.getY()/SZ, xint = e.getX()/SZ;
            // convert to args only clicks with valid coordinates
            Point tmp = new Point(xint, yint);
            if (!isInside(tmp) || SwingUtilities.isRightMouseButton(e)) {
                if(pStart != null) {
                    pStart = pMoving = null;
                    repaint();
                }
                return;
            }
            if (pStart == null) {
                if (pieces.size() >= N) {
                    if (debug)
                        System.out.println("Enough pieces already");
                    return;
                }
                if (!isValidEndPoint(tmp)) {
                    if (debug)
                        System.out.println("Invalid start at " + tmp);
                    return;
                }
                pStart = tmp;
                pMoving = null;
                repaint();
                if (debug)
                    System.out.println("Starting a cut at " + tmp);
                return;
            }
            if (debug)
                System.out.println("Attempting a cut to " + tmp);
            String errmes = makeCut(pStart, tmp);
            pStart = pMoving = null;
            repaint();
            if (!errmes.equals("")) {
                addFatalError(errmes);
                return;
            }
            //After a new manual cut, saved redo's can't be used anymore
            redos.clear();
        }
        public void mouseClicked(MouseEvent e) { }
        public void mouseReleased(MouseEvent e) { }
        public void mouseEntered(MouseEvent e) { }
        public void mouseExited(MouseEvent e) { }
        public void mouseDragged(MouseEvent e) {}
        public void mouseMoved(MouseEvent e) {
            if (pStart != null) {
                pMoving = new Point(e.getX() - SZ/2,e.getY() - SZ/2);
                repaint();
            }
        }
    }
    // -----------------------------------------
    public CakeSharingVis(String seed) {
      try {
        if (vis) {
            jf = new JFrame();
            jf.setTitle("Seed " + seed);
            v = new Vis();
            JScrollPane sp = new JScrollPane(v);
            jf.getContentPane().add(sp);
        }
        if (exec != null) {
            try {
                Runtime rt = Runtime.getRuntime();
                proc = rt.exec(exec);
                os = proc.getOutputStream();
                is = proc.getInputStream();
                br = new BufferedReader(new InputStreamReader(is));
                new ErrorReader(proc.getErrorStream()).start();
            } catch (Exception e) { e.printStackTrace(); }
        }
        System.out.println("Score = " + runTest(seed));
        if (proc != null)
            try { proc.destroy(); } 
            catch (Exception e) { e.printStackTrace(); }
      }
      catch (Exception e) { e.printStackTrace(); }
    }
    // -----------------------------------------
    public static void main(String[] args) {
        seed = "1";
        vis = true;
        manual = false;
        SZ = 0; //Auto-fit to desktop size
        plain = false;
        save = false;
        showColors = false;
        showPoints = true;
        showValues = true;

        for (int i = 0; i<args.length; i++) {
            if (args[i].equals("-seed"))
                seed = args[++i];
            if (args[i].equals("-exec"))
                exec = args[++i];
            if (args[i].equals("-novis"))
                vis = false;
            if (args[i].equals("-manual"))
                manual = true;
            if (args[i].equals("-size"))
                SZ = Integer.parseInt(args[++i]);
            if (args[i].equals("-debug"))
                debug = true;
            if (args[i].equals("-plain"))
                plain = true;
            if (args[i].equals("-save"))
                save = true;
            if (args[i].equals("-color"))
                showColors = true;
            if (args[i].equals("-nopoints"))
                showPoints = false;
            if (args[i].equals("-novalues"))
                showValues = true;
        }
        if (exec == null)
            manual = true;
        if (manual)
            vis = true;

        CakeSharingVis f = new CakeSharingVis(seed);
    }
    // -----------------------------------------
    void addFatalError(String message) {
        System.out.println(message);
	}
}

class ErrorReader extends Thread {
	InputStream error;

	public ErrorReader(InputStream is) {
		error = is;
	}

	public void run() {
		try {
			byte[] ch = new byte[50000];
			int read;
            while ((read = error.read(ch)) > 0)
            {   String s = new String(ch,0,read);
				System.out.print(s);
				System.out.flush();
			}
        } catch(Exception e) { }
	}
}