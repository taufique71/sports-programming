#include <iostream>
using namespace std;

int main()
{
    char c;
    int count=0;
    int flag=0;
    while((c=getchar())!=EOF)
    {
        if(c=='\n')
        {
            cout<<count<<"\n";
            count=0;
            flag=0;
        }
        else if((c>=65&&c<=90)||(c>=97&&c<=122))
        {
			if(flag==0)
			{
				flag=1;
				count++;
			}
        }
        else flag=0;
    }
    return 0;
}

