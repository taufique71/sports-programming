#include <iostream>
#define MAX_i 30050
#define MAX_j 12
using namespace std;

int coins[MAX_j] = {0,5,10,20,50,100,200,500,1000,2000,5000,10000};
long long int table[MAX_i][MAX_j];

void coin_count(void)
{
    int i,j;

    for(j = 0 ; j < MAX_j ; j++) table[0][j] = 1;

    for(i = 1; i < MAX_i ; i++)
    {
        for(j = 1 ; j < MAX_j ; j++)
        {
            int c = i - coins[j];
            if(c >= 0) table[i][j] = table[c][j] + table[i][j - 1];
            else table[i][j] = 0 + table[i][j - 1];
        }
    }
}

int main()
{
    double dollars_f;
    coin_count();

    while(cin >> dollars_f)
    {
        if(dollars_f == 0.00) break;
        int cents;
        cents = (int)(dollars_f * 100 + 1E-5);
        printf("%6.2lf%17lld\n" , dollars_f , table[cents][MAX_j - 1]);
    }
    return 0;
}
