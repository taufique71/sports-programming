#include <iostream>
using namespace std;

int main()
{
    float area,animal,para,count;
    int cases,farmer;
    cin>>cases;
    while(cases--)
    {
        cin>>farmer;
        count=0;
        while(farmer--)
        {
            cin>>area>>animal>>para;
            count=count+(((area/animal)*para)*animal);
        }
        printf("%0.0f",count);
        if(!((cases==0)&&(farmer==0))) cout<<endl;
    }
    return 0;
}
