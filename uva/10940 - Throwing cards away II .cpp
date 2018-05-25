#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    double d;
    int i,j;
    while(cin >> n)
    {
        if(n == 0) break;
        else if(n == 1) cout << 1 << endl;
        else
        {
            d = 0;
            while(pow(2,d) < n) d++;
            i = (int)pow(2,(d-1));
            cout << 2*(n-i) << endl;
        }
    }
}
