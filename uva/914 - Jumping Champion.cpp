#include <iostream>
#define MAX 1000000
#define MAX_DIFF 1000
using namespace std;

int prime[MAX];

void sieve()
{
    int i,j;

    prime[0] = 1;
    prime[1] = 1;

    for(i = 2 ; i < MAX ;)
    {
        if(i*i > MAX) break;
        for(j = i+i ; j < MAX ; j+=i) prime[j] = 1;
        for(i++;(i < MAX)&&(prime[i]!=0);i++);
    }
}

int main()
{
    sieve();
    int lower,upper;
    int n_case;

    scanf("%d",&n_case);
    while(n_case--)
    {
        scanf("%d %d", &lower,&upper);

        int i , j , prev = -1 , now = -1;
        int track[MAX_DIFF];
        int count;

        for(i = 0 ; i < MAX_DIFF ; i++) track[i] = 0;

        for(i = lower ; i <= upper ; i++)
        {
            if(prime[i] == 0)
            {
                count++;
                if((prev < 0)&&(now < 0)) prev = i;
                else
                {
                    now = i;
                    track[now-prev]++;
                    prev = now;
                }
            }
        }

        if(count > 2)
        {
            int max_diff = 0;
            int max_count = track[max_diff];
            int flag = 1;

            for(i = 1 ; i < MAX_DIFF ; i++)
            {
                if(track[i] > max_count)
                {
                    max_diff = i;
                    max_count = track[max_diff];
                    flag = 1;
                }
                else if(track[i] == max_count) flag = 0;
            }

            if(flag == 0) printf("No jumping champion\n");
            else printf("The jumping champion is %d\n",max_diff);
        }
        else printf("No jumping champion\n");
    }
    return 0;
}
