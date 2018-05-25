#include <iostream>
using namespace std;

/*unsigned long int toggle(unsigned long int i,unsigned long int res)
{
    unsigned long int one=1;
    return (res^(one<<i));
}

int main()
{
    unsigned long int one=1,a,b,res=0;
    while(cin>>a>>b)
    {
        res=0;
        for(int i=1;i<=32;i++)
        {
            if(((a&(one<<i))>>i)^((b&(one<<i))>>i)) res=toggle(i,res);
        }
        cout<<res<<endl;
    }
    return 0;
}*/

int main()
{
    unsigned long long int a,b;
    while(cin>>a>>b)
    {
        cout<<(a^b)<<endl;
    }
}
