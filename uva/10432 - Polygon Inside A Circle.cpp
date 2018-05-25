#include <iostream>
#include <cmath>
using namespace std;

#define pi 2*acos(0.0)

double triangle(double a,double s)
{
    double h,area;
    h=sqrt((a*a)-(s*s));
    area=0.5*s*h;
    return area;
}

int main()
{
    double n,r;
    double area_p,area_t,theta,a,x;
    while(cin>>r>>n)
    {
        theta=2*pi/n;
        a=(pi-theta)/2;
        x=(r*sin(theta))/sin(a);
        area_t=triangle(r,x/2);
        area_p=n*area_t;
        printf("%0.3lf\n",2*area_p);
    }
    return 0;
}
