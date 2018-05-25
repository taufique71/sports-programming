#include <iostream>
#define MAX 1000000
using namespace std;

int prime[MAX+10]={1};

void seive()
{
    long int i,j;
    for(i=0;i<=MAX;i++) prime[i]=1;

    prime[0]=0;
    prime[1]=0;

    for(i=2;i<=MAX;)
    {
        if((i*i)>MAX) break;
        for(j=i+i;j<=MAX;j=j+i) prime[j]=0;
        for (i++; !prime[i]; i++);
    }
}

void print(long int n)
{
    long int i,j;
    for(i=3,j=n-i;i<=j;i++,j--)
    {
        if(prime[i]&&prime[j]) break;
    }
    cout<<n<<" = "<<i<<" + "<<j<<endl;
}

int main(void)
{
    long int n;
    seive();
    while(cin>>n)
    {
        if(n==0) break;
        print(n);
    }
    return 0;
}
