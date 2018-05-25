#include <iostream>
using namespace std;

int main()
{
    int n;
    long long int ans;

    while(cin >> n)
    {
        if(n >= 0)
        {
            if(n < 8) cout << "Underflow!" << endl;
            else if(n > 13) cout << "Overflow!" << endl;
            else
            {
                ans = 1;
                for(int i = 1 ; i <= n ; i++) ans *= i;
                cout << ans << endl;
            }
        }
        else
        {
            n = -1 * n;
            if(n % 2) cout << "Overflow!" << endl;
            else cout << "Underflow!" << endl;
        }
    }

    return 0;
}
