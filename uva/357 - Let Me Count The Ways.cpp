#include <iostream>

#define MAX_j 6
#define MAX_i 30050

using namespace std;

int coin[MAX_j] = {0,1,5,10,25,50};
long long int table[MAX_i][MAX_j];

void coinChange()
{
    int i,j;

    for(i = 0 ; i < MAX_i ; i++) table[i][0] = 0;
    for(j = 0 ; j < MAX_j ; j++) table[0][j] = 1;

    for(i = 1 ; i < MAX_i ; i++)
    {
        for(j = 1 ; j < MAX_j ; j++)
        {
            if((i - coin[j]) >= 0)
            {
                table[i][j] = table[i - coin[j]][j] + table[i][j - 1];
            }
            else table[i][j] = 0 + table[i][j - 1];
        }
    }
}

int main()
{
    int cn;
    long long int res;
    coinChange();

    while(cin >> cn)
    {
        res = table[cn][MAX_j - 1];
        if(res == 1) cout << "There is only 1 way to produce " << cn << " cents change." << endl;
        else cout << "There are " << res <<" ways to produce " << cn << " cents change." << endl;
    }

    return 0;
}
