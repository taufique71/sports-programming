#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double n_case;
    double x1,y1,x2,y2,x3,y3,x4,y4;
    double a1,b1,c1,a2,b2,c2;
    double D,Dx,Dy;
    cin >> n_case;

    cout << "INTERSECTING LINES OUTPUT" << endl;

    while(n_case--)
    {
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

        a1 = y1-y2;
        b1 = x2-x1;
        c1 = a1*x1 + b1*y1;

        a2 = y3-y4;
        b2 = x4-x3;
        c2 = a2*x3 + b2*y3;

        D = a1*b2 - a2*b1;
        if(D != 0)
        {
            Dx = c1*b2 - c2*b1;
            Dy = a1*c2 - a2*c1;

            double x = Dx / D;
            double y = Dy / D;

            printf("POINT %0.2lf %0.2lf\n",x,y);
        }
        else
        {
            if(c2 != 0)
            {
                if(a2 != 0)
                {
                    if(a1/a2 == c1/c2) cout << "LINE" << endl;
                    else cout << "NONE" << endl;
                }
                else
                {
                    if(b1/b2 == c1/c2) cout << "LINE" << endl;
                    else cout << "NONE" << endl;
                }
            }
            else
            {
                if(c1 == 0) cout << "LINE" << endl;
                else cout << "NONE" << endl;
            }
        }
    }

    cout << "END OF OUTPUT" << endl;

    return 0;

}
