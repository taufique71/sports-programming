#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n_case;
    double r1,r2,r3;
    double a,b,c;
    double A,B,C;
    double area_1,area_2,area_3,area_triange,area_result;
    double s;

    cin >> n_case;

    while(n_case--)
    {
        cin >> r1 >> r2 >> r3;

        a = r2+r3;
        b = r1+r3;
        c = r1+r2;
        s = (a+b+c)/2;
        area_triange = sqrt(s*(s-a)*(s-b)*(s-c));

        A = acos((b*b + c*c - a*a)/(2*b*c));
        B = acos((a*a + c*c - b*b)/(2*a*c));
        C = acos((a*a + b*b - c*c)/(2*a*b));

        area_1 = (A*r1*r1)/2;
        area_2 = (B*r2*r2)/2;
        area_3 = (C*r3*r3)/2;

        area_result = area_triange - area_1 - area_2 - area_3;

        printf("%0.6lf\n",area_result);
    }

    return 0;
}
