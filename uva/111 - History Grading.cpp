#include <iostream>
using namespace std;

int n;

int lcs(int cor[], int ans[])
{
    int table[n+1][n+1];
    int i , j;

    for(i = 0 ; i <= n ; i++)
    {
        table[i][0] = 0;
        table[0][i] = 0;
    }

    for(i = 1 ; i <= n ; i++)
    {
        for(j = 1 ; j <= n ; j++)
        {
            if(cor[i] == ans[j]) table[i][j] = table[i - 1][j - 1] + 1;
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
    cin >> n;
    int *cor = new int [n + 1];
    int *ans = new int [n + 1];

    int i = 1;
    int event;
    cor[0] = 0;
    while(i <= n)
    {
        cin >> event;
        cor[event] = i;
        i++;
    }

    while(cin >> event)
    {
        ans[0] = 0;
        i = 1;
        ans[event] = i;
        i++;
        while(i <= n)
        {
            cin >> event;
            ans[event] = i;
            i++;
        }
        cout << lcs(cor , ans) << endl;
    }

    return 0;
}
