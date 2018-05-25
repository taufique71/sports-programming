#include <iostream>
#define maxp 25
using namespace std;

int prime[maxp]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
char blank[]=" ";

int getcount(int n,int p)
{
    int i;
    int sum=0;
    for(i=p;i<=n;i*=p)
    {
        sum+=n/i;
    }
    return sum;
}

void calc(int n)
{
    int count,times=1,first=1;
    printf("%3d! =",n);
    for(int i=0;i<maxp;i++)
    {
        count=getcount(n,prime[i]);
        if(count!=0)
        {
            if(times%15==1)
            {
                if(first)
                {
                    printf("%3d",count);
                    first=0;
                }
                else
                {
                    cout<<endl;
                    printf("%6s",blank);
                    printf("%3d",count);
                }
            }
            else
            {
                printf("%3d",count);
            }
        }
        times++;
    }
}

int main()
{
    int n;
    while(cin>>n)
    {
        if(!n) break;
        calc(n);
        cout<<endl;
    }
    return 0;
}

