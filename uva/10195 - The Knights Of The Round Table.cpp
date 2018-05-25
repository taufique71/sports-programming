#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a,b,c,s,result;

    while(scanf("%lf %lf %lf",&a,&b,&c) == 3)
    {
        s = (a+b+c)/2;
        result = sqrt((s-a)*(s-b)*(s-c)/s);
        if( a == 0.0 || b == 0.0 || c == 0.0) result = 0.0;
        printf("The radius of the round table is: %0.3lf\n",result);
    }

    return 0;
}
