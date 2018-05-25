#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char n1[10],n2[10];
    int len1,len2;

    while(scanf("%s %s",&n1,&n2)==2)
    {
        if(n1[0]=='0'&&n2[0]=='0') break;
        len1=strlen(n1);
        len2=strlen(n2);

        int ad1=0,ad2=0,count=0,car=0,i=0,j=0;
        for(i=len1-1,j=len2-1;i>=0||j>=0;i--,j--)
        {
            if(i>=0) ad1=n1[i]-48;
            else ad1=0;

            if(j>=0) ad2=n2[j]-48;
            else ad2=0;

            if((ad1+ad2+car)>9)
            {
                car=(ad1+ad2+car)/10;
                count++;
            }
            else car=0;
        }
        if(count==1) cout<<count<<" "<<"carry operation."<<"\n";
        else if(count==0) cout<<"No carry operation."<<"\n";
        else if(count>0) cout<<count<<" "<<"carry operations."<<"\n";
    }
    return 0;
}
