#include <iostream>
#include <cmath>

#define pi 3.141592653589793

using namespace std;

int main()
{
    double x1,y1,x2,y2,x3,y3;
    while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)
    {
        double a = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
        double b = sqrt((x2 - x3)*(x2 - x3) + (y2 - y3)*(y2 - y3));
        double c = sqrt((x1 - x3)*(x1 - x3) + (y1 - y3)*(y1 - y3));
        double s = (a + b + c) / 2;
        double K = sqrt(s * (s-a) * (s-b) * (s-c));
        double R = (a * b * c) / (4 * K);
        double C = (2 * pi * R);
        printf("%0.2lf\n",C);
    }
    return 0;
}
