#include <stdio.h>
#include <math.h>

int dec(int m);
int hex(int m);

int main(void)
{
    int n,m;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&m);
        printf("%d ",dec(m));
        printf("%d\n",hex(m));
    }
    return 0;
}

int dec(int m)
{
    int count=0;
    while(m)
    {
        m=m&(m-1);
        count++;
    }
    return count;
}

int hex(int m)
{
    int i=0,j,count=0,n;

    while(m)
    {
        n=m%10;
        while(n)
        {
            n=n&(n-1);
            count++;
        }
        m=floor(m/10);
    }
    return count;
}
