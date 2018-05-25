#include <iostream>
#define LL unsigned long long int
using namespace std;

LL min(LL a, LL b)
{
    if(a < b) return a;
    else return b;
}

LL abs(LL a)
{
    if(a < 0) return ((-1)*a);
    else return a;
}

int main()
{
    LL m,n;
    LL result;
    LL linear,diagonal;
    LL a,b;

    while(cin >> a >> b)
    {
        if(a == 0 && b == 0) break;
        if(a >= b)
        {
            m = a;
            n = b;
        }
        else
        {
            m = b;
            n = a;
        }
        linear = m*n*(m-1) + m*n*(n-1);
        a = min(m,n)-1;
        diagonal = 2*(2*(a*(a+1)*(2*a+1)/6 - a*(a+1)/2) + ((abs(m-n)+1)*min(m,n)*(min(m,n)-1)));
        result = linear+diagonal;
        cout << result << endl;
    }
    return 0;
}
