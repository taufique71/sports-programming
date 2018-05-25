#include <iostream>
#include <cstring>
using namespace std;

char mirror[129]={'\0'};

int ismirror(char *str);
int ispalindrome(char *str);

int main()
{
    char str[21];
    mirror['A']='A';
    mirror['B']='\0';
    mirror['C']='\0';
    mirror['D']='\0';
    mirror['E']='3';
    mirror['F']='\0';
    mirror['G']='\0';
    mirror['H']='H';
    mirror['I']='I';
    mirror['J']='L';
    mirror['K']='\0';
    mirror['L']='J';
    mirror['M']='M';
    mirror['N']='\0';
    mirror['O']='O';
    mirror['P']='\0';
    mirror['Q']='\0';
    mirror['R']='\0';
    mirror['S']='2';
    mirror['T']='T';
    mirror['U']='U';
    mirror['V']='V';
    mirror['W']='W';
    mirror['X']='X';
    mirror['Y']='Y';
    mirror['Z']='5';
    mirror['1']='1';
    mirror['2']='S';
    mirror['3']='E';
    mirror['4']='\0';
    mirror['5']='Z';
    mirror['6']='\0';
    mirror['7']='\0';
    mirror['8']='8';
    mirror['9']='\0';
    while(cin>>str)
    {
        if(ismirror(str))
        {
            if(ispalindrome(str)) cout<<str<<" -- is a mirrored palindrome."<<endl;
            else cout<<str<<" -- is a mirrored string." <<endl;
        }
        else
        {
            if(ispalindrome(str)) cout<<str<<" -- is a regular palindrome."<<endl;
            else cout<<str<<" -- is not a palindrome." <<endl;
        }
        cout<<endl;
    }
    return 0;
}

int ismirror(char *str)
{
    int flag=1;
    int i,j;
    for(i=0,j=strlen(str)-1;i<=j;i++,j--)
    {
        if(i==j)
        {
            if(mirror[str[i]]=='\0') flag=0;
        }
        else
        {
            if(mirror[str[i]]!=str[j])
            {
                flag=0;
                break;
            }
        }
    }
    return flag;
}

int ispalindrome(char *str)
{
    int flag=1,i,j;
    for(i=0,j=strlen(str)-1;i<j;i++,j--)
    {
        if(str[i]!=str[j])
        {
            flag=0;
            break;
        }
    }
    return flag;
}
