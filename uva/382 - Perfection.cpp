#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    int flag=0,verdict=-1;
    long int a,c;
    long int sum=0;
    while(cin>>a)
    {
        if(a==0) break;
        if(flag==0) cout<<"PERFECTION OUTPUT"<<endl;
        if(a==1) printf("%5ld  DEFICIENT\n",a);
        else{
        flag++;
        sum=0;
        c=floor(sqrt(a));
        for(int i=1;i<=c;i++)
        {
            if(!(a%i))
            {
                sum=sum+i;
                if(i!=1)sum=sum+(a/i);
            }
        }
        if(sum==a) printf("%5ld  PERFECT\n",a);
        else if(sum>a) printf("%5ld  ABUNDANT\n",a);
        else if(sum<a) printf("%5ld  DEFICIENT\n",a);
        }
    }
    cout<<"END OF OUTPUT"<<endl;
    return 0;
}
