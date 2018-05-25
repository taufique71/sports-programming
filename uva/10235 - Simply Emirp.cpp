#include<iostream>
#define MAX 1000000
using namespace std;

int prime[MAX];

void sieve()
{
    int i,j;

    prime[0] = 1;
    prime[1] = 1;

    for(i = 2 ; i < MAX ; )
    {
        if(i*i > MAX) break;
        for(j =i + i ; j < MAX ; j += i) prime[j] = 1;
        for(i++ ; (prime[i] != 0) && (i < MAX) ; i++);
    }
}

int main()
{
    sieve();

    int input;
    int temp;
    int reverse;

    while(scanf("%d",&input) == 1)
    {
        if(prime[input] == 1) printf("%d is not prime.\n",input);
        else
        {
            temp = input;
            reverse = 0;

            while(temp > 0)
            {
                reverse = reverse*10 + (temp%10);
                temp = temp / 10;
            }

            if(prime[reverse] == 0 && input != reverse) printf("%d is emirp.\n",input);
            else printf("%d is prime.\n",input);
        }
    }

    return 0;
}
