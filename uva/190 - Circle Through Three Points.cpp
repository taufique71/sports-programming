#include <iostream>
#include <cmath>
using namespace std;

void print_first(double Cx,double Cy,double r)
{
    printf("(x ");
    if(Cx > 0.00) printf("-");
    else printf("+");
    printf(" %0.3lf)^2 + (y ",fabs(Cx));
    if(Cy > 0.00) printf("-");
    else printf("+");
    printf(" %0.3lf)^2 = %0.3lf^2",fabs(Cy),r);
    cout << endl;
}

void print_second(double c,double d,double e)
{
    printf("x^2 + y^2 ");
    if(c < 0.00) printf("-");
    else printf("+");
    printf(" %0.3lfx ",fabs(c));
    if(d < 0.00) printf("-");
    else printf("+");
    printf(" %0.3lfy ",fabs(d));
    if(e < 0.00) printf("-");
    else printf("+");
    printf(" %0.3lf = 0",fabs(e));
    cout << endl;
}

int main()
{
    double x1,y1,x2,y2,x3,y3;
    double a1,b1,c1,a2,b2,c2;
    double Cx,Cy;
    double D,Dx,Dy;
    double r,g,f,c,d,e;

    while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)
    {
        //if(flag) cout << endl;
        //else flag = true;

        a1 = 2*(x2-x1); //derived from concept: let centre (x,y). then distance from (x,y) to (x1,y1),(x2,y2) and (x3,y3) are same.
        b1 = 2*(y2-y1); //derived from concept: let centre (x,y). then distance from (x,y) to (x1,y1),(x2,y2) and (x3,y3) are same.
        c1 = x2*x2 - x1*x1 + y2*y2 - y1*y1; //derived from concept: let centre (x,y). then distance from (x,y) to (x1,y1),(x2,y2) and (x3,y3) are same.

        a2 = 2*(x3-x1);
        b2 = 2*(y3-y1);
        c2 = x3*x3 - x1*x1 + y3*y3 - y1*y1;

        D = a1*b2 - a2*b1;
        Dx = c1*b2 - c2*b1;
        Dy = a1*c2 - a2*c1;

        Cx = Dx/D;
        Cy = Dy/D;

        r = sqrt((Cx-x1)*(Cx-x1) + (Cy-y1)*(Cy-y1));
        g = -1 * Cx;
        f = -1 * Cy;

        c = 2 * g;
        d = 2 * f;
        e = g*g + f*f - r*r;

        print_first(Cx,Cy,r);
        print_second(c,d,e);
        cout << endl;
    }
    return 0;
}
