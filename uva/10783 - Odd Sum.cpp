#include <iostream>
using namespace std;

int main()
{
    int a,b,c,cases=0;
    long int sum;
    cin>>c;
    while(c--)
    {
        cases++;
        sum=0;
        cin>>a>>b;
        while(a<=b)
        {
            if(!(a%2)) a=a+1;
            sum+=a;
            a+=2;
        }
        cout<<"Case "<<cases<<':'<<' '<<sum<<endl;
    }
    return 0;
}
