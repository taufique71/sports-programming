#include <iostream>
using namespace std;

#define MIN 0

int main()
{
    int c,tot,n;
    cin>>c;
    while(c--)
    {
        cin>>n;
        tot=n;
        int grade[n+MIN];
        int i=0;
        while(n--)
        {
            cin>>grade[i];
            i++;
        }
        long int sum=0;
        for(i=0;i<tot;i++) sum=sum+grade[i];
        double avg=sum/tot;
        double count=0;
        for(i=0;i<tot;i++)
        {
            if(grade[i]>avg) count++;
        }
        printf("%0.3lf",(count*100/tot));
        cout<<'%'<<endl;
    }
    return 0;
}
