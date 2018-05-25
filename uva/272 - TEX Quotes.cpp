#include <iostream>
using namespace std;

void print(char c);

int main()
{
    long long int flag=0;
    char c;
    while((c=getchar())!=EOF)
    {
        if(c=='"')
        {
            if(flag%2==0) print('`');
            else print('\'');
            flag++;
        }
        else putchar(c);
    }
    return 0;
}

void print(char c)
{
    cout<<c;
    cout<<c;
    return ;
}
