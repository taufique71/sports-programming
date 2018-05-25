#include <iostream>

#define MAX 1000005
#define SMAX 1005

using namespace std;

int top=0;
int Prime[SMAX];
int Count[MAX];
int prime[500];

void Seive()
{
    long int i,j;

    for(i=0;i<SMAX;i++)
    {
        Prime[i]=1;
        Count[i]=0;
    }

    Prime[0]=0;
    Prime[1]=0;

    for(i=2;i<SMAX;)
    {
        if((i*i)>SMAX) break;
        for(j=i+i;j<SMAX;j+=i) Prime[j]=0;
        for(i++;(i<SMAX)&&(!Prime[i]);i++);
    }

    for(i=top;i<SMAX;i++)
    {
        if(Prime[i])
        {
            prime[top]=i;
            top++;
        }
    }
}

long int Times(long int n)
{
    int l=top;
    long int i,c=0;

    for(i=0;(i<l)&&(prime[i]*prime[i]<=n);i++)
    {
        if(n%prime[i]==0)
        {
            while(n%prime[i]==0)
            {
                c++;
                n=n/prime[i];
            }
        }
    }

    if(n>1) c++;

    return c;
}

void Calc()
{
    long int i,c=1;

    Count[0]=0;
    Count[1]=0;
    Count[2]=1;

    for(i=3;i<MAX;i++)
    {
        c+=Times(i);
        Count[i]=c;
    }

    return;
}

int main()
{
    long int n;

    Seive();
    Calc();
    while(cin>>n)
    {
        cout<<Count[n]<<endl;
    }

    return 0;
}
