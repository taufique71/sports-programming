#include <iostream>
#define SIZE 130
using namespace std;

char open1='(';
char open3='[';
char close1=')';
char close3=']';

class stack
{
    int tos;
    char arr[SIZE];
public:
    stack()
    {
        tos=-1;
        arr[0]='\0';
    }
    void push(char c)
    {
        tos++;
        arr[tos]=c;
    }
    char pop()
    {
        char c;
        c=arr[tos];
        tos--;
        return c;
    }
    int size()
    {
        return (tos+1);
    }
    void reinit()
    {
        tos=-1;
    }
};

int main()
{
    stack s;

    int num,flag=1;

    char str[SIZE];

    char ch;

    cin>>num;
    cin.get(ch);

    while(num--)
    {
        flag=1;
        gets(str);
        int i=0;
        s.reinit();

        while(str[i]!='\0')
        {
            if(flag==0) break;

            if((str[i]==open1)||(str[i]==open3))
            {
                s.push(str[i]);
                flag=1;
            }

            else if((s.size()>0)&&(str[i]==close1))
            {
                if(s.pop()==open1) flag=1;
                else flag=0;
            }

            else if((s.size()>0)&&(str[i]==close3))
            {
                if(s.pop()==open3) flag=1;
                else flag=0;
            }

            else if(s.size()<=0)
            {
                flag=0;
                break;
            }

            i++;
        }

        if((s.size()==0)&&(flag==1)&&(str[i]=='\0')) cout<<"Yes"<<endl;

        else cout<<"No"<<endl;
    }
    return 0;
}
