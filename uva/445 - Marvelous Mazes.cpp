#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    char c;
    int count=0;
    while((c=getchar())!=EOF)
    {
		if(c=='\n') cout<<'\n';
        if((c>=48)&&(c<=57)) count=count+c-48;
        else if(((c>=65)&&(c<=90))||(c=='*'))
        {
            while(count--) cout<<c;
			count++;
        }
        else if(c=='!')
        {
			cout<<endl;
        }
        else if(c='b')
        {
            while(count--) cout<<' ';
			count++;
		}
    }
    return 0;
}
