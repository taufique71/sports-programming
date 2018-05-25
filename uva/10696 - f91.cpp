#include <iostream>
using namespace std;

/*long long int f91(long long int n)
{
    if(n<=100) return f91(f91(n+11));
    else if(n>=101) return (n-10);
}

int main()
{
    long long int n,res;
    while(cin>>n)
    {
        if(n==0) break;
        else
        {
            res=f91(n);
        }
        printf("f91(%lld) = %lld\n",n,res);
    }
    return 0;
}*/

int main()
{
    long int n,res;
    while(cin>>n)
    {
        if(n==0) break;
        if(n<=100) res=91;
        else res=n-10;
        printf("f91(%ld) = %ld\n",n,res);
    }
    return 0;

}
