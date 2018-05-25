#include <iostream>
#include <cmath>
#include <cstdio>
//#define e exp(1)
using namespace std;

int p,q,r,s,t,u;
double f(double x)
{
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}
int main()
{
    double a,b,c;
    while(scanf("%d %d %d %d %d %d",&p,&q,&r,&s,&t,&u) == 6)
    {
        a = 0.00;
        b = 1.00;
        double v1 = f(a);
        double v2 = f(b);
        if(v1*v2>0.00)
        {
            printf("No solution\n");
        }
        else
        {
            while(true)
            {
                double c = f((a+b)/2.00);
                if(v2*c<=0.00)
                {
                    a = (a+b)/2;
                    v1 = c;
                }
                else
                {
                    b = (a+b)/2;
                    v2 = c;
                }
                if(fabs(a-b) <= 1e-8)
                {
                    printf("%0.4lf\n",(a+b)/2.00);
                    break;
                }
            }
        }
    }
    return 0;
}
