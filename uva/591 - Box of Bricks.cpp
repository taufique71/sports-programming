#include <iostream>
using namespace std;

long int abs(long int a,int b)
{
    if(a>=b) return (a-b);
    else return (b-a);
}

int main()
{
    long int stack,sum=0,avg,move=0;
    int n[100],i,m[100],cases=0;
    while(cin>>stack)
    {
        if(stack==0) break;
        cases++;
        for(i=0;i<stack;i++)
        {
            cin>>n[i];
            sum=sum+n[i];
        }
        avg=sum/stack;
        for(i=0;i<stack;i++) move=move+abs(avg-n[i]);
        cout<<"Set #"<<cases<<'\n';
        cout<<"The minimum number of moves is "<<move/2<<".\n\n";
        sum=0;
        move=0;
    }
    return 0;
}
