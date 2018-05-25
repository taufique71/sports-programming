#include <iostream>
#include <cmath>
#include <vector>
#define MAX 46400

using namespace std;

vector<int> Prime;
int prime[MAX+1];

void seive()
{
    long int i,j;
    for(i=0;i<MAX;i++) prime[i]=1;

    prime[0]=0;
    prime[1]=0;

    for(i=2;i<=MAX;)
    {
        if((i*i)>(MAX-1)) break;
        for(j=i+i;j<MAX;j=j+i) prime[j]=0;
        for (i++; (i<MAX)&&(!prime[i]); i++);
    }

    for(i=0;i<MAX;i++)
    {
        if(prime[i]!=0) Prime.push_back(i);
    }
}

void print_s(long int n)
{
    cout<<n<<" =";
    if(n<0) cout<<" -1 x";
}

long int mod(long int n)
{
    if(n>=0) return n;
    else return (-n);
}

void calc(long int n)
{
    long int i=0,s,p=0;
    s=sqrt(n);
    for(p=Prime[i];(n!=1)&&(Prime[i]<=s);i++)
    {
        while(!(n%Prime[i]))
        {
            n=n/Prime[i];
            if(n!=1) cout<<' '<<Prime[i]<<" x";
            else cout<<' '<<Prime[i];
        }
    }
    if(n!=1) cout<<' '<<n<<endl;
    else cout<<endl;
}

int main()
{
    long int n;
    seive();
    while(cin>>n)
    {
        if(!n) break;
        else
        {
            print_s(n);
            calc(mod(n));
        }
    }
    return 0;
}
