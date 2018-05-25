#include <iostream>
using namespace std;

bool track_row[10];
int result[8];
int chessboard[8][8];
int in;
int m;

int check()
{
    int i,j,r1,r2,c1,c2;
    double slope;

    j = in-1;
    r1 = result[j];
    c1 = j;

    if(j != 0)
    {
        for(i = 0 ; i < j ; i++)
        {
            r2 = result[i];
            c2 = i;

            slope = ((double)r1 - (double)r2)/((double)c1 - (double)c2);
            if(slope == 1 || slope == -1) return 0;
        }
    }

    return (in+1);
}

void backtrack(int c)
{
    int flag,i;
    int temp = 0;

    flag = check();

    if(flag == 0) return;
    else if(flag == 9)
    {
        for(i = 0 ; i < in ; i++)
        {
            temp += chessboard[i][result[i]];
        }
        if(temp > m) m = temp;
        return;
    }

    for(i = 0 ; i < 8 ; i++)
    {
        if(track_row[i])
        {
            track_row[i] = false;
            result[in] = i;
            in++;
            backtrack(c+1);
            in--;
            track_row[i] = true;
        }
    }
}

int main()
{
    int n_case;
    int i,j;

    cin >> n_case;

    while(n_case--)
    {
        for(i = 0 ; i < 8 ; i++)
        {
            for(j = 0 ; j < 8 ; j++) cin >> chessboard[i][j];
            track_row[i] = true;
        }
        in = 0;
        m = 0;

        backtrack(0);
        printf("%5d\n",m);
    }

    return 0;
}
