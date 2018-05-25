#include <iostream>
#include <cstdio>
using namespace std;

int isalpha(char c)
{
    if((c>64&&c<91)||(c>96&&c<123)) return 1;
    else return 0;
}

int main()
{
    int n,i,j,tempn=0,flag=1;
    char arr[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int count[26]={0};
    char c,tempc='\0';
    cin>>n;
    scanf("\n");
    while(n--)
    {
        while((c=getchar())!='\n')
        {
            if(isalpha(c))
            {
                if(c>64&&c<91) count[c-65]++;
                else count[c-97]++;
            }
        }
    }
    for(i=0;i<26;i++)
    {
        for(j=0;j<25;j++)
        {
            if(count[j]<count[j+1])
            {
                tempn=count[j];
                count[j]=count[j+1];
                count[j+1]=tempn;
                tempc=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=tempc;
            }
        }
    }

    for(i=0;i<26;i++)
    {
        if(count[i]==0) break;
        cout<<arr[i]<<' '<<count[i]<<endl;
    }
    return 0;
}
