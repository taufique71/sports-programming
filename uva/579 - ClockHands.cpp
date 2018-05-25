#include <iostream>
using namespace std;

float abs(float a)
{
    if(a>=0) return a;
    else return -a;
}

int main()
{
    float hr,min,ahr,amin,res;
    char c;
    while(cin>>hr>>c>>min)
    {
        if(hr==0&&min==0) break;
        ahr=hr*30+((min/60)*30);
        amin=min*360/60;
        if(abs(ahr-amin)<=180) res=abs(ahr-amin);
        else res=360-abs(ahr-amin);
        printf("%0.3f\n",res);
    }
    return 0;
}
