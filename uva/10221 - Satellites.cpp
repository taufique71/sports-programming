#include <iostream>
#include <cmath>

#define pi acos(-1)

using namespace std;

int main()
{
    double radius , arc , chord , A ;
    char angle[5];

    while(cin >> radius >> A >> angle)
    {
        radius = radius + 6440;

        if(angle[0] == 'm') A /= 60.0;
        if(A > 180.0) A = 360.0 - A;

        A = (A * pi) / 180.0 ;

        arc = radius * A ;
        chord = 2.0 * radius * sin(A / 2.0);

        printf("%0.6lf %0.6lf\n",arc,chord);
    }

    return  0;
}
