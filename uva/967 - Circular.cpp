#include <iostream>
#include <cstring>
#define MAX 1000001

using namespace std;

int prime[MAX];
int cnt[MAX];

int circular(int n)
{
    char num[20];
    char temp[20];
    sprintf(num,"%d",n);
    int len = strlen(num);
    int flag = 1;
    int i,j;

    for(i = 1 ; i <= len ; i++)
    {
        temp[0] = num[len-1];
        for(j = 1 ; j < len ; j++)
        {
            temp[j] = num[j-1];
        }
        temp[j] = '\0';
        sscanf(temp,"%d",&n);
        if(prime[n])
        {
            flag = 0;
            break;
        }
        strcpy(num,temp);
    }
    if(flag == 1) return 1;
    else return 0;
}

void sieve_circular()
{
    int i,j;
    prime[0] = 1;
    cnt[0] = 0;
    prime[1] = 1;
    cnt[1] = 0;

    for(i = 2 ; i < MAX ;)
    {
        if(i*i > MAX) break;
        for(j = i+i ; j < MAX ;j += i) prime[j] = 1;
        for(i++;(i < MAX)&&(prime[i]) ; i++);
    }

    for(i = 0 ; i < MAX ; i++)
    {
        if(prime[i] == 0)
        {
            if(circular(i))
            {
                cnt[i] = cnt[i-1]+1;
            }
            else cnt[i] = cnt[i-1];
        }
        else cnt[i] = cnt[i-1];
    }
}

int main()
{
    sieve_circular();
    int first,second,result;
    while(cin >> first)
    {
        if(first < 0) break;
        cin >> second;
        result = cnt[second]-cnt[first-1];

        if(result > 1) printf("%d Circular Primes.\n",result);
        else if(result == 0) printf("No Circular Primes.\n");
        else printf("1 Circular Prime.\n");
    }
    return 0;
}
