#include <iostream>

using namespace std;

long long int square(long long int n)
{
    return (n*n);
}

/******************  Big Mod Under devide and conquer rule ************************/

long long int mod (long long int b,long long int p,long long int m)
{
    if(p == 0) return 1;

    else if((p % 2) == 0) return (square(mod(b,p/2,m)) % m);

    else return (((b % m) * mod(b,p-1,m)) % m);
}

int main()
{
    long long int b,p,m;
    while(cin >> b >> p >> m)
    {
        cout << mod(b,p,m)<<endl;
    }
    return 0;
}
