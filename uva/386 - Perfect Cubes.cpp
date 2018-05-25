#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int a , b , c , d;
    int count = 0;

    for(a = 2 ; a <= 200 ; a++)
    {
        for(b = 2 ; b <= 200 ; b++)
        {
            for(c = b ; c <= 200 ; c++)
            {
                for(d = c ; d <= 200 ; d++)
                {
                    if(a*a*a == (b*b*b + c*c*c + d*d*d))
                    {
                        vector<int> temp;
                        temp.push_back(b);
                        temp.push_back(c);
                        temp.push_back(d);

                        sort(temp.begin() , temp.end());
                        cout << "Cube = " << a << ", Triple = (" << temp[0] << "," << temp[1] << "," << temp[2] << ")" << endl;
                        break;
                    }
                    if(a*a*a < (b*b*b + c*c*c + d*d*d)) break;
                }
            }
        }
    }

    return 0;
}
