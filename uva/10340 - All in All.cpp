#include <iostream>
using namespace std;

int subseq(char s1[],char s2[]);

int main()
{
    char s1[100000],s2[100000];
    while(cin>>s1>>s2)
    {
        if(subseq(s1,s2)) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}

int subseq(char s1[],char s2[])
{
    int i,j;
    int flag=0,pos=0;
    for(i=0;i<strlen(s1);i++)
    {
        flag=0;
        for(j=pos;j<strlen(s2);j++)
        {
            if(s1[i]==s2[j])
            {
                flag=1;
                break;
            }
        }
        if(flag)
        {
            pos=j+1;
            continue;
        }
        else return flag;
    }
    return flag;
}
