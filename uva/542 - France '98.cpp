#include <iostream>
#include <cstring>
#include <cstdio>
#include <iomanip>
using namespace std;

int main()
{
	char team[16][15];
	double table[16][16];
	double dp_probability[16][10];
	int i,j,k,r;
	int count;

    for(i = 0; i < 16 ; i++) cin >> team[i];
    for(i = 0 ; i < 16 ; i++)
    {
        for(j = 0 ; j < 16 ; j++)
        {
            scanf("%lf",&table[i][j]);
            table[i][j] = table[i][j] / 100;
        }
    }
    count = 2;
    for(i = 0 ; i < 16 ;i++)
    {
        for(j = 0 ; j < 10 ; j++)
        {
            if(j == 0) dp_probability[i][j] = 1;
            else dp_probability[i][j] = 0;
        }
    }

    r = 1;
    for(count = 2 ; count <= 16 ; count *= 2)
    {
        for(i = 0 ; i < 16 ; i+= count)
        {
            for(j = i ; j < i+count ; j++)
            {
                int m = (i+i+count)/2;
                if(j >= m)
                {
                    for(k = i ; k < m ; k++) dp_probability[j][r] += dp_probability[j][r-1]*dp_probability[k][r-1]*table[j][k];
                }
                else
                {
                    for(k = m ; k < i+count ; k++) dp_probability[j][r] += dp_probability[j][r-1]*dp_probability[k][r-1]*table[j][k];
                }
            }
        }
        r++;
    }

    for(i = 0 ; i < 16 ; i++)
    {
        dp_probability[i][r-1] *= 100;
        cout << left;
        cout << setw(10);
        cout << team[i];
        printf(" p=%0.2lf",dp_probability[i][r-1]);
        cout << '%' << endl;

    }

	return 0;
}
