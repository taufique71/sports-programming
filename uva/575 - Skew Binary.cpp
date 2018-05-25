#include <iostream>
#include <cstring>
using namespace std;

long int power(int n,int j)
{
    long int res=1;
    int i;
    for(i=0;i<j;i++)
    {
        res=res*n;
    }
    return res;
}

int main()
{
    char num[100];
    int k,i;
    while(cin>>num)
    {
        if(!strcmp(num,"0")) break;
        int len=strlen(num);
        long int dec=0;
        for(i=len-1;i>=0;i--)
        {
            k=len-i;
            dec=dec+(num[i]-48)*(power(2,k)-1);
        }
        cout<<dec<<endl;
    }
    return 0;
}
