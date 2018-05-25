#include <iostream>

#define MAX 60

using namespace std;

long long int dp[MAX][MAX];
int cuts[MAX];
long long int length;
long long int n_cut;

void init()
{
    int i,j;

    for(i = 0 ; i < MAX ; i++)
    {
        for(j = 0 ; j < MAX ; j++)
        {
            dp[i][j] = 0;
        }
        cuts[i] = 0;
    }
}

long long int calculate()
{
    int n = n_cut;
    int l,i,j,k,q;
    long long int min;
    long long int inf = 100000000;

    for(i = 0 ; i < n ; i++)
    {
        dp[i][i] = 0;
        dp[i][i+1] = 0;
    }

    for(l = 2 ; l < n ; l++)
    {
        for(i = 0 ; i < (n - l) ; i++)
        {
            j = i + l;

            dp[i][j] = inf;

            for(k = i ; k < j ; k++)
            {
                q = dp[i][k] + dp[k][j] + cuts[j] - cuts[i];
                if(q < dp[i][j])
                {
                    dp[i][j] = q;
                }
            }
        }
    }

    return dp[0][n-1];
}

int main()
{
    int i;

    while(cin >> length)
    {
        if(length == 0) break;

        cin >> n_cut;
        init();

        cuts[0] = 0;
        i = 1;
        while(i <= n_cut)
        {
            cin >> cuts[i];
            i++;
        }
        cuts[i] = length;

        n_cut += 2;

        cout << "The minimum cutting is " << calculate() << "." << endl;
    }

    return 0;
}
