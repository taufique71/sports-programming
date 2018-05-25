#include <iostream>
#include <cstring>
using namespace std;

typedef struct bottle
{
    long long int b;
    long long int g;
    long long int c;
}btl;

int main()
{
    btl b1,b2,b3;
    long long int count=4294967296;
    char str[]="GCB";
    while(scanf("%lld %lld %lld %lld %lld %lld %lld %lld %lld",&b1.b,&b1.g,&b1.c,&b2.b,&b2.g,&b2.c,&b3.b,&b3.g,&b3.c)==9)
    {
        count=4294967296;
        strcpy(str,"GCB");
        {
            if(((b1.c+b1.g)+(b2.b+b2.g)+(b3.b+b3.c))<count)
            {
                count=((b1.c+b1.g)+(b2.b+b2.g)+(b3.b+b3.c));
                strcpy(str,"BCG");
            }
            else if(((b1.c+b1.g)+(b2.b+b2.g)+(b3.b+b3.c))==count)
            {
                if(strcmp(str,"BCG")>0)
                strcpy(str,"BCG");
            }
        }

        {
            if(((b1.c+b1.g)+(b2.b+b2.c)+(b3.b+b3.g))<count)
            {
                count=((b1.c+b1.g)+(b2.b+b2.c)+(b3.b+b3.g));
                strcpy(str,"BGC");
            }
            else if(((b1.c+b1.g)+(b2.b+b2.c)+(b3.b+b3.g))==count)
            {
                if(strcmp(str,"BGC")>0)
                strcpy(str,"BGC");
            }
        }

        {
            if(((b1.c+b1.b)+(b2.b+b2.g)+(b3.g+b3.c))<count)
            {
                count=((b1.c+b1.b)+(b2.b+b2.g)+(b3.g+b3.c));
                strcpy(str,"GCB");
            }
            else if(((b1.c+b1.b)+(b2.b+b2.g)+(b3.g+b3.c))==count)
            {
                if(strcmp(str,"GCB")>0)
                strcpy(str,"GCB");
            }
        }

        {
            if(((b1.b+b1.g)+(b2.c+b2.g)+(b3.b+b3.c))<count)
            {
                count=((b1.b+b1.g)+(b2.c+b2.g)+(b3.b+b3.c));
                strcpy(str,"CBG");
            }
            else if(((b1.b+b1.g)+(b2.c+b2.g)+(b3.b+b3.c))==count)
            {
                if(strcmp(str,"CBG")>0)
                strcpy(str,"CBG");
            }
        }

        {
            if(((b1.b+b1.g)+(b2.b+b2.c)+(b3.g+b3.c))<count)
            {
                count=((b1.b+b1.g)+(b2.b+b2.c)+(b3.g+b3.c));
                strcpy(str,"CGB");
            }
            else if(((b1.b+b1.g)+(b2.b+b2.c)+(b3.g+b3.c))==count)
            {
                if(strcmp(str,"CGB")>0)
                strcpy(str,"CGB");
            }
        }

        {
            if(((b1.c+b1.b)+(b2.c+b2.g)+(b3.b+b3.g))<count)
            {
                count=((b1.c+b1.b)+(b2.c+b2.g)+(b3.b+b3.g));
                strcpy(str,"GBC");
            }
            else if(((b1.c+b1.b)+(b2.c+b2.g)+(b3.b+b3.g))==count)
            {
                if(strcmp(str,"GBC")>0)
                strcpy(str,"GBC");
            }
        }
        cout<<str<<" "<<count<<"\n";
    }
    return 0;
}
