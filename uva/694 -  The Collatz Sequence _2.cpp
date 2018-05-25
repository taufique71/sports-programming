#include <iostream>
using namespace std;

int main()
{
    long long int a,l,track;
    long int count;
    int cases=0;
    while(cin>>a>>l)
    {
        if((a<0)||(l<0)) break;
        cases++;
        track=a;
        count=0;
        while(!((a==1)||(a>l)))
        {
            if(a%2) a=(3*a)+1;
            else a=a/2;
            count++;
        }
        if(a==1) count++;
        cout<<"Case "<<cases<<": A = "<<track<<", limit = "<<l<<", number of terms = "<<count<<endl;
    }
    return 0;
}
