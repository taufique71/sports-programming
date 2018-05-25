#include <iostream>
#include <cstring>
using namespace std;

char first[1001];
char second[1001];

int lcs(void)
{
    int m = strlen(first);
    int n = strlen(second);
    int i,j;

    int table[m + 1][n + 1];

    for(i = 0 ; i <= m ; i++) table[i][0] = 0;
    for(j = 0 ; j <= n ; j++) table[0][j] = 0;

    for(i = 1 ; i <= m ; i++)
    {
        for(j = 1 ; j <= n ; j++)
        {
            if(first[i - 1] == second[j - 1]) table[i][j] = table[i - 1][j - 1] + 1;
            else
            {
                if(table[i - 1][j] >= table[i][j - 1]) table[i][j] = table[i - 1][j];
                else table[i][j] = table[i][j - 1];
            }
        }
    }

    return table[i - 1][j - 1];
}

int main()
{
    while(gets(first))
    {
        gets(second);
        cout << lcs() << endl;
    }

    return 0;
}
