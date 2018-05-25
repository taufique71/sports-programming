#include <iostream>

#define MAX_PRIME 1000001

using namespace std;

int prime[MAX_PRIME];
int result[MAX_PRIME];
char str[10];
int sum;
int a,b;

void seive()
{
    prime[0] = 1;
    result[0] = 0;
    prime[1] = 1;
    result[1] = 0;

    int i,j;

    for(i = 2 ; i < MAX_PRIME ;)
    {
        for(j = i+i ; j < MAX_PRIME ; j += i) prime[j] = 1;

        sprintf(str,"%d",i);
        sum = 0;
        for(a = 0; str[a]; a++) sum += str[a]-48;

        if(prime[sum] == 0) result[i] = result[i-1] + 1;
        else result[i] = result[i-1];

        for(i++; (i < MAX_PRIME)&&(prime[i] != 0) ;i++) result[i] = result[i-1];
    }
}

int main()
{
    seive();

    int lim1;
    int lim2;
    int n_case;

    scanf("%d",&n_case);

    while(n_case--)
    {
        scanf("%d %d",&lim1,&lim2);
        printf("%d\n",result[lim2]-result[lim1-1]);
    }

}
