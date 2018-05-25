#include <iostream>
using namespace std;

int valid(long int a,long int b,long int c);
int equi(long int a,long int b,long int c);
int iso(long int a,long int b,long int c);

int main()
{
    int cases,casen=1;
    long int a=0,b=0,c=0;
    cin>>cases;
    while(cases--)
    {
        cin>>a>>b>>c;
        if(valid(a,b,c))
        {
            if(equi(a,b,c)) cout<<"Case "<<casen<<": Equilateral\n";
            else if(iso(a,b,c)) cout<<"Case "<<casen<<": Isosceles\n";
            else cout<<"Case "<<casen<<": Scalene\n";
        }
        else cout<<"Case "<<casen<<": Invalid\n";
        casen++;
    }
    return 0;
}

int valid(long int a,long int b,long int c)
{
    if(((a+b)>c)&&((b+c)>a)&&((a+c)>b)) return 1;
    else return 0;
}

int equi(long int a,long int b,long int c)
{
    if((a==b)&&(b==c)) return 1;
    else return 0;
}

int iso(long int a,long int b,long int c)
{
    if(a==b) return 1;
    else if(b==c) return 1;
    else if(a==c) return 1;
    else return 0;
}
