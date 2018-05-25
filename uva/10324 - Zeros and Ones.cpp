#include <iostream>
#define MAX 1000001
using namespace std;

int dp[MAX];

int main()
{
    char input;
    char last;
    int l,u,temp;
    int case_count = 1;
    int n_case;

    while(cin >> last)
    {
        printf("Case %d:\n",case_count);

        int i = 1;
        dp[0] = 0;
        while(1)
        {
            input = getchar();
            if(input == '\n') break;
            if(input == last) dp[i] = dp[i-1];
            else dp[i] = dp[i-1]+1;

            last = input;
            i++;
        }

        scanf("%d",&n_case);

        while(n_case--)
        {
            scanf("%d %d",&l,&u);

            if(l > u)
            {
                temp = l;
                l = u;
                u = temp;
            }

            if(dp[l] == dp[u]) printf("Yes\n");
            else printf("No\n");
        }

        case_count++;
    }
    return 0;
}
