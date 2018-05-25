#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long int second , root , x , y , i , j , count = 0 , remainingSteps;

    while(cin >> second)
    {
        if(second == 0) break;

        root = floor(sqrt(second));
        remainingSteps = second - (root*root);

        if(second == (root*root))
        {
            if(root % 2){x = 1; y = root;}
            else {x = root; y = 1;}
        }

        else
        {
            count = root * root;

            if(root % 2)
            {
                y = root + 1;
                for(i = 1 ; i <= (root + 1) ; i++)
                {
                    x = i;
                    count++;
                    if(count == second) break;
                }

                if(count != second)
                {
                    for(i = root ; i >= 0 ; i--)
                    {
                        y = i;
                        count++;
                        if(count == second) break;
                    }
                }
            }

            else
            {
                x = root + 1;
                for(i = 1 ; i <= (root + 1) ; i++)
                {
                    y = i;
                    count++;
                    if(count == second) break;
                }

                if(count != second)
                {
                    for(i = root ; i >= 0 ; i--)
                    {
                        x = i;
                        count++;
                        if(count == second) break;
                    }
                }
            }
        }
        cout << x << ' ' << y << endl;
    }

    return 0;
}
