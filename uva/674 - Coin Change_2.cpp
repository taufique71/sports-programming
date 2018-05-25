#include <iostream>
#define MAX 10000
using namespace std;

int coins[6] = {0,1,5,10,25,50};
long long int table[MAX][6];

void coin_count(void)
{
    int i,j;

    for(j = 0 ; j < 6 ; j++) table[0][j] = 1;

    for(i = 1; i < MAX ; i++)
    {
        for(j = 1 ; j < 6 ; j++)
        {
            int c = i - coins[j];
            if(c >= 0) table[i][j] = table[c][j] + table[i][j - 1];
            else table[i][j] = 0 + table[i][j - 1];
        }
    }
}

int main()
{
    int cents;
    coin_count();

    while(cin >> cents)
    {
        cout << table[cents][5] << endl;
    }
    return 0;
}
