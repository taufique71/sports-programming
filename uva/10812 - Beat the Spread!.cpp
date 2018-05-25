#include <iostream>
using namespace std;

int main()
{
    long long int n,a,b,s,d;
    cin >> n;

    while(n--)
    {
        cin >> s >> d;
        if((s < d) || ((s - d) % 2 == 1)) cout << "impossible" << endl;
        else
        {
            a = (s + d) / 2;
            b = (s - d) / 2;
            cout << a << ' ' << b << endl;
        }
    }

    return 0;
}
