#include <iostream>
using namespace std;

int main()
{
    long long int p[51]={0};
    int i=0;

    p[0]=0;
    p[1]=1;
    p[2]=2;
    p[3]=3;

    for(i=4;i<51;i++)
    {
        p[i]=p[i-1]+p[i-2];
    }

    while(cin>>i)
    {
        if(!i) break;
        cout<<p[i]<<endl;
    }

    return 0;
}
