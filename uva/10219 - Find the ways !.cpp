#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long int n , r , p , q , result;

    while(cin >> n >> r)
    {
        if((n - r) > r)
        {
            p = r;
            q = (n - r);
        }
        else
        {
            p = n - r;
            q = r;
        }

        double upor = 0;
        double nich = 0;

        for(int i = 0 ; i < p ; i++)
        {
            upor += log10(q + 1 + i);
            nich += log10(1 + i);
        }

        result = floor(upor - nich) + 1;

        cout << result << endl;
    }
}
