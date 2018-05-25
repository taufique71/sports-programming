#include <iostream>
using namespace std;

unsigned long long int f[100];
unsigned long long int m[100];

void gen()
{
    int i;

    f[0]=1;
    m[0]=0;

    for(i=1;i<100;i++)
    {
        f[i] = m[i-1] + f[0];
        m[i] = m[i-1] + f[i-1];
    }
    return;
}

int main()
{
    int n;

    gen();

    while(cin>>n)
    {
        if(n<0) break;
        cout<<m[n]<<' '<<m[n]+f[n]<<endl;
    }

    return 0;
}
