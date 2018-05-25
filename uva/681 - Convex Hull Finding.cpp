
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>

using namespace std;

struct Point
{
    int x;
    int y;
}ref;

vector<Point> points;

int is_left_special(Point p0, Point p1, Point p2)
{
    long int cross_product = (p1.x - p0.x)*(p2.y - p0.y) - (p2.x - p0.x)*(p1.y - p0.y);
    if(cross_product > 0) return 1;
    else if(cross_product < 0) return -1;
    else return 0;
}

bool is_left(Point p0, Point p1, Point p2)
{
    long int cross_product = (p1.x - p0.x)*(p2.y - p0.y) - (p2.x - p0.x)*(p1.y - p0.y);
    if(cross_product > 0) return true;
    else if(cross_product < 0) return false;
    else
    {
        if((p1.x == p0.x)&&(p1.y == p0.y)) return true;
        else if((p2.x == p0.x)&&(p2.y == p0.y)) return false;
        else return true;
    }
}

bool compare(Point p2, Point p1)
{
    return (!is_left(ref , p1 , p2));
}

void sort_points()
{
    ref.y = 2147483647;
    ref.x = 2147483647;

    int i = 0,count;
    int n_points = points.size();

    for(i = 0 ; i < n_points ; i++)
    {
        if(points[i].y < ref.y) ref = points[i];
        else if((points[i].y == ref.y)&&(points[i].x < ref.x)) ref = points[i];
    }

    sort(points.begin(),points.end(),compare);
}

void graham_scan()
{
    stack<Point> final;
    int i = 0;
    int count = 0;
    int n_points = points.size();
    int flag = 0;

    if(i < n_points)
    {
        final.push(points[i]);
        i++;
        count++;
    }

    if(i < n_points)
    {
        final.push(points[i]);
        i++;
        count++;
    }

    Point p0,p1,p2;

    while((count <= n_points) && (count > 1))
    {
        p2 = points[i%n_points];
        p1 = final.top();
        final.pop();
        p0 = final.top();

        flag = is_left_special(p0,p1,p2);
        if(flag > 0)
        {
            final.push(p1);
            final.push(p2);
            i++;
            count++;
        }
        else if(flag == 0)
        {
            double distance1 = sqrt((p0.x - p1.x)*(p0.x - p1.x) + (p0.y - p1.y)*(p0.y - p1.y));
            double distance2 = sqrt((p0.x - p2.x)*(p0.x - p2.x) + (p0.y - p2.y)*(p0.y - p2.y));
            if(distance1 >= distance2) final.push(p1);
            else final.push(p2);
            i++;
            count++;
        }
    }

    points.clear();
    while(!final.empty())
    {
        points.insert(points.begin(),final.top());
        final.pop();
    }

    while(points.size()<3) points.push_back(points[0]);
}

int main()
{
    int n_input_set;
    int n_input_vertex;
    int n_output_vertex;
    int delim;
    Point input;

    while(cin >> n_input_set)
    {
        cout << n_input_set << endl;

        while(n_input_set--)
        {
            cin >> n_input_vertex;
            points.clear();
            while(n_input_vertex--)
            {
                cin >> input.x >> input.y;
                points.push_back(input);
            }
            if(n_input_set) cin >> delim;
            if(points.size() > 0)
            {
                sort_points();
                graham_scan();
                n_output_vertex = points.size();
                cout << n_output_vertex << endl;
                for(int i = 0 ; i < n_output_vertex ; i++) cout << points[i].x << ' ' << points[i].y << endl;
            }
            if(n_input_set) cout << delim << endl;
        }
    }

	return 0;
}

/*********************************************************************************
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

typedef struct
{
    int x,y;
}coord;

coord MV(int x1, int y1, int x2, int y2);
int cross(coord a, coord b);
double distance(coord a, coord b);
coord pivot;

int comp_func(const void *a, const void *b)
{
    coord vect1, vect2;
    int crs;
    double d1, d2;
    coord *p = (coord *)a;
    coord *q = (coord *)b;
    vect1 = MV(pivot.x, pivot.y, p->x, p->y);
    vect2 = MV(pivot.x, pivot.y, q->x, q->y);
    crs = cross(vect1, vect2);
    if(crs>0)
        return -1;
    else if(crs<0)
        return 1;
    else if(crs==0)
    {
        d1=distance(pivot, *p);
        d2=distance(pivot, *q);
        if(d1>d2)
            return 1;
        else
            return -1;
    }
    else
        return 0;
}

int main()
{
    int n, test, last;
    while(scanf("%d", &test)==1)
    {
        printf("%d\n", test);
        while(test--)
        {
            scanf("%d", &n);
            if(n==0)
                break;
            int i, j, minp;
            coord cord[1500], min, temp;
            for(i=0;i<n;i++)
            {
                scanf("%d%d", &cord[i].x, &cord[i].y);
            }
            if(test>0)
                scanf("%d", &last);
            for(i=0;i<n;i++)
            {
                if(i==0)
                {
                    min=cord[i];
                    minp=i;
                }
                else
                {
                    if(cord[i].y < min.y)
                    {
                        min=cord[i];
                        minp=i;
                    }
                    else if(cord[i].y==min.y)
                    {
                        if(cord[i].x<min.x)
                        {
                            min=cord[i];
                            minp=i;
                        }
                    }
                }
            }
            temp=cord[0];
            cord[0]=min;
            cord[minp]=temp;
            pivot=cord[0];
            qsort(cord, n, sizeof(coord), comp_func);

            coord stck[1500];
            int rr=-1;
            stck[++rr]=cord[0];
            stck[++rr]=cord[1];
            for(i=2;i<n;)
            {
                if(rr>0)
                {
                    coord vec1, vec2;
                    int n1, n2, crs;
                    vec1=MV(stck[rr-1].x, stck[rr-1].y, stck[rr].x, stck[rr].y);
                    vec2=MV(stck[rr].x, stck[rr].y, cord[i].x, cord[i].y);
                    crs=cross(vec1, vec2);

                    if(crs<=0)
                    {
                        rr=rr-1;
                        continue;
                    }
                }
                stck[++rr]=cord[i];
                i++;

            }
            int cnt=1;
            for(i=0;i<=rr;i++)
            {
                if(i>0 && stck[i].x == pivot.x && stck[i].y == pivot.y);
                else cnt++;

            }
            printf("%d\n", cnt);
            for(i=0;i<=rr;i++)
            {
                if(i>0 && stck[i].x == pivot.x && stck[i].y == pivot.y);
                else printf("%d %d\n", stck[i].x, stck[i].y);
            }
            printf("%d %d\n", stck[0].x, stck[0].y);
            if(test>0)
                printf("-1\n");
        }
    }
    return 0;
}

coord MV(int x1, int y1, int x2, int y2)
{
    coord temp;
    temp.x = x2-x1;
    temp.y = y2-y1;
    return temp;
}

int cross(coord a, coord b)
{
    return (a.x*b.y - a.y*b.x);
}

double distance(coord a, coord b)
{
    double d1, d2;
    d1 = a.x - b.x;
    d2 = a.y - b.y;
    return sqrt(d1*d1+d2*d2);
}
**************************************************************************************/
