#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

unsigned long int is_pallindrome(unsigned long int n);
unsigned long int reverse(unsigned long int n);
void str_rev(char *ptr);

int main()
{
    unsigned long int n;
    int count=0,cases;
    cin>>cases;
    while(cases--)
    {
        count=0;
        cin>>n;
        while(!is_pallindrome(n))
        {
            count++;
            n=n+reverse(n);
        }
        cout<<count<<" "<<n<<"\n";
    }
    return 0;
}

unsigned long int reverse(unsigned long int n)
{
    char ar[11];
    sprintf(ar,"%ld",n);
    str_rev(ar);
    sscanf(ar,"%ld",&n);
    return n;
}

unsigned long int is_pallindrome(unsigned long int n)
{
    char ar1[11];
    char ar2[11];
    sprintf(ar1,"%ld",n);
    sprintf(ar2,"%ld",n);
    str_rev(ar2);
    if(!strcmp(ar1,ar2)) return 1;
    else return 0;
}

void str_rev(char *ptr)
{
    char temp;
    int i,j;
    for(i=0,j=strlen(ptr)-1;i<j;i++,j--)
    {
        temp=*(ptr+i);
        *(ptr+i)=*(ptr+j);
        *(ptr+j)=temp;
    }
    return ;
}
