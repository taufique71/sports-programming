#include <iostream>
#include <queue>

#define MAX_COL 150
#define MAX_ROW 150

using namespace std;

char field[MAX_ROW][MAX_COL];
int m , n;

struct point
{
    int row;
    int col;
};

void foodFill(int row , int col , char target , char replace)
{
    queue<point> Q ;

    int i , j;

    if(field[row][col] != target) return;

    point centre;
    point now;
    point west;
    point east;

    centre.row = row;
    centre.col = col;

    Q.push(centre);

    while(Q.size() > 0)
    {
        now = Q.front();
        Q.pop();

        if(field[now.row][now.col] == '@')
        {
            west = now;
            east = now;

            for(i = west.row, j = west.col ; (field[i][j] == target)&&(j >= 0) ; j--);
            west.col = j + 1;

            for(i = east.row, j = east.col ; (field[i][j] == target)&&(j < n) ; j++);
            east.col = j - 1;

            for(i = west.row,j = west.col ; j <= east.col ; j++)
            {
                field[i][j] = replace;

                if(field[i-1][j] == target)
                {
                    now.row = i - 1;
                    now.col = j;

                    Q.push(now);
                }

                if(field[i+1][j] == target)
                {
                    now.row = i+1;
                    now.col = j;

                    Q.push(now);
                }

                if(field[i-1][j-1] == target)
                {
                    now.row = i-1;
                    now.col = j-1;

                    Q.push(now);
                }

                if(field[i+1][j-1] == target)
                {
                    now.row = i+1;
                    now.col = j-1;

                    Q.push(now);
                }

                if(field[i-1][j+1] == target)
                {
                    now.row = i-1;
                    now.col = j+1;

                    Q.push(now);
                }

                if(field[i+1][j+1] == target)
                {
                    now.row = i+1;
                    now.col = j+1;

                    Q.push(now);
                }
            }
        }
    }

    return;
}

void print()
{
    int i , j;

    for(i = 0 ; i < m ; i++)
    {
        for(j = 0 ; j < n ; j++) cout << field[i][j];
        cout << endl;
    }
}

int main()
{
    int count = 0;
    int i,j;

    while(cin >> m)
    {
        if(m == 0) break;

        cin >> n;

        count = 0;

        for(int i = 0 ; i < (m + 2) ; i++)
        {
            if(i == 0)
            {
                for(j = 0 ; j < n+2 ; j++) field[i][j] = '*';
            }

            else if(i < (m + 1))
            {
                for(int j = 0 ; j < (n + 2) ; j++)
                {
                    if(j == 0) field[i][j] = '*';
                    else if(j < (n + 1)) cin >> field[i][j];
                    else if(j == (n + 1)) field[i][j] = '*';
                }
            }

            else if(i == (m + 1))
            {
                for(j = 0 ; j < n+2 ; j++) field[i][j] = '*';
            }
        }

        n = n + 2;
        m = m + 2;

        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(field[i][j] == '@')
                {
                    foodFill(i , j , '@' , '*');
                    count++;
                }
            }
        }

        cout << count << endl;
    }

    return 0;
}
