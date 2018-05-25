#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long int n;
    while(cin>>n)
    {
        if(n==0) break;
        if(floor(sqrt(n))==ceil(sqrt(n))) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}
