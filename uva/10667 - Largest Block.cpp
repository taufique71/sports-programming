#include <iostream>
using namespace std;

int main()
{
    int n_case;
    int size;
    int n_blocks;
    int r1,c1,r2,c2;
    int i,j,m,n;
    int max,desired,current;

    cin >> n_case;
    while(n_case--)
    {
        cin >> size;
        cin >> n_blocks;

        short int board[size][size];
        for(i = 0 ; i < size ; i++)
        {
            for(j = 0 ; j < size ; j++) board[i][j] = 1;
        }

        while(n_blocks--)
        {
            cin >> r1 >> c1 >> r2 >> c2;
            r1--;
            c1--;
            r2--;
            c2--;
            for(i = r1 ; i <= r2 ; i++)
            {
                for(j = c1 ; j <= c2 ; j++) board[i][j] = 0;
            }
        }

        /*cout << endl;
        for(i = 0 ; i < size ; i++)
        {
            for(j = 0 ; j < size ; j++) cout << board[i][j] << '\t';
            cout << endl;
        }
        cout << endl;*/

        short int sum[size][size];
        for(i = 0 ; i < size ; i++)
        {
            for(j = 0 ; j  < size ; j++)
            {
                if(i == 0 && j == 0) sum[i][j] = board[i][j];
                else if(i == 0) sum[i][j] = sum[i][j-1] + board[i][j];
                else if(j == 0) sum[i][j] = sum[i-1][j] + board[i][j];
                else sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + board[i][j];
            }
        }

        /*cout << endl;
        for(i = 0 ; i < size ; i++)
        {
            for(j = 0 ; j < size ; j++) cout << sum[i][j] << '\t';
            cout << endl;
        }
        cout << endl;*/

        max = 0;
        for(i = 0 ; i < size ; i++)
        {
            for(j = 0 ; j < size ; j++)
            {
                for(m = i ; m < size ; m++)
                {
                    for(n = j ; n < size ; n++)
                    {
                        desired = (m-i+1)*(n-j+1);
                        if(i == 0 && j == 0) current = sum[m][n];
                        else if(i == 0) current = sum[m][n] - sum[m][j-1];
                        else if(j == 0) current = sum[m][n] - sum[i-1][n];
                        else current = sum[m][n] - sum[i-1][n] - sum[m][j-1] + sum[i-1][j-1];

                        if(desired == current)
                        {
                            if(current > max) max = current;
                        }
                    }
                }
            }
        }
        cout << max << endl;
    }

    return 0;
}
