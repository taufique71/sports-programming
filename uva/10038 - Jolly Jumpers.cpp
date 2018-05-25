#include <iostream>
using namespace std;

int abs(int n);

int main()
{
    int n,num,flag,i;
    while(scanf("%d",&n)==1)
    {
        int array[3000];
        int count[3000]={0};
        for(i=0;i<n;i++) cin>>array[i];
        for(i=0;i<n-1;i++)
        {
            num=abs(array[i]-array[i+1]);
            if(count[num]!=0) break;
            else count[num]=1;
        }
        int flag=1;
        for(i=1;i<n;i++)
        {
            if(count[i]==0)
            {
                flag=0;
                break;
            }
        }
        if(flag==1) cout<<"Jolly\n";
        else if(flag==0) cout<<"Not jolly\n";
    }
    return 0;
}

int abs(int n)
{
    if(n>=0) return n;
    else return -n;
}

