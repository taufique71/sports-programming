#include <iostream>
#define MAX 2001
#define MAX_ASCII 128
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
        for(j = i+i ; j < MAX ; j += i) prime[j] = 1;
        for(i++;(prime[i]!=0) && (i < MAX) ; i++);
    }
}

int main()
{
    sieve();
    int n_case;
    int case_count = 1;
    int i,j;
    char input[MAX];

    scanf("%d",&n_case);

    while(case_count <= n_case)
    {
        scanf("%s",input);
        int frequency[128] = {0};
        printf("Case %d: ",case_count);
        for(i = 0 ; input[i] ; i++) frequency[input[i]]++;
        int count = 0;
        for(i = '0' ; i < 128 ; i++)
        {
            if(prime[frequency[i]] == 0)
            {
                printf("%c",i);
                count++;
            }
        }
        if(count == 0) printf("empty");
        cout << endl;
        case_count++;
    }

    return 0;
}
