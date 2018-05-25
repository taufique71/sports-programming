#include <iostream>
using namespace std;

int main()
{
    long long int n;
    long long int result;

    while(cin >> n)
    {
        result = 3 * ((2*((n/2+1)*(n/2+1)))-3);
        cout << result << endl;
    }

    return 0;
}
