#include <iostream>
using namespace std;

int main()
{
    double x1,x2,y1,y2;

    while(cin >> x1 >> y1 >> x2 >> y2)
    {
        double mx,my;

        mx = (x1 + x2) / 2;
        my = (y1 + y2) / 2;

        double dx = mx - x1;
        double dy = my - y1;

        double x3,y3,x4,y4;

        x3 = mx + dy;
        y3 = my - dx;
        x4 = mx - dy;
        y4 = my + dx;

        printf("%0.10lf %0.10lf %0.10lf %0.10lf\n",x3,y3,x4,y4);
    }

    return 0;
}
