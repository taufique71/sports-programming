#include <iostream>
#include <cstring>
#define MAX 1010
using namespace std;

int dp[MAX][MAX];
char input[MAX];
int l,r;
int len;
const int inf = 2147483647;

int min(int a,int b,int c)
{
    if(a <= b)
    {
        if(a <= c) return a;
        else return c;
    }
    else
    {
        if(b <= c) return b;
        else return c;
    }
}

void solve()
{
    int i,j;
    for(i = 0 ; i <= len+1 ; i++)
    {
        for(j = 0 ; j <= len+1 ; j++)
        {
            if(i >= j) dp[i][j] = 0;
            else dp[i][j] = inf;
        }
    }

    for(j = l ; j <= r ; j++)
    {
        for(i = j ; i >= 1 ; i--)
        {
            if(i >= j) dp[i][j] = 0;
            else if(input[i-1] == input[j-1]) dp[i][j] = dp[i+1][j-1];
            else dp[i][j] = 1 + min(dp[i+1][j-1],dp[i+1][j],dp[i][j-1]);
        }
    }
}

/*int solve(int l,int r)
{
    if(l >= r) return 0;
    else if(input[l] == input[r]) return solve(l+1,r-1);
    else return (1+min(solve(l+1,r-1),solve(l,r-1),solve(l+1,r)));
}*/

int main()
{
    int n_case;
    int case_count = 1;
    //int l,r;
    cin >> n_case;

    while(case_count <= n_case)
    {
        cin >> input;
        l = 1;
        len = strlen(input);
        r = len;
        solve();
        printf("Case %d: %d\n",case_count,dp[l][r]);
        case_count++;
    }

    return 0;
}
