#include <iostream>
#include <queue>

#define MAX 202

using namespace std;

struct grid
{
    int row;
    int col;
};

char board[MAX][MAX];
char nothing = ' ';
char white = 'w';
char black = 'b';
char red = 'r';
char green = 'g';

void init()
{
    int i , j;

    for(i = 0 ; i < MAX ; i++)
    {
        for(j = 0 ; j < MAX ; j++) board[i][j] = nothing;
    }
}

void flood_fill(int row , int col , char target , char replace)
{
    queue<grid> q;
    int i , j;

    if(board[row][col] != target) return;

    grid now;
    grid center;
    grid west;
    grid east;

    now.row = row;
    now.col = col;

    q.push(now);

    while(!q.empty())
    {
        now = q.front();
        q.pop();

        east = now;
        west = now;

        for(i = west.row, j = west.col; board[i][j] == target ; j--);
        west.col = j+1;

        for(i = east.row, j = east.col; board[i][j] == target ; j++);
        east.col = j-1;

        for(i = west.row, j = west.col ; j <= east.col ; j++)
        {
            board[i][j] = replace;

            now.row = i;
            now.col = j;

            if(board[i][j-1] == target)
            {
                now.row = i;
                now.col = j-1;

                q.push(now);
            }

            if(board[i-1][j-1] == target)
            {
                now.row = i-1;
                now.col = j-1;

                q.push(now);
            }

            if(board[i-1][j] == target)
            {
                now.row = i-1;
                now.col = j;

                q.push(now);
            }

            if(board[i+1][j] == target)
            {
                now.row = i+1;
                now.col = j;

                q.push(now);
            }

            if(board[i][j+1] == target)
            {
                now.row = i;
                now.col = j+1;

                q.push(now);
            }

            if(board[i+1][j+1] == target)
            {
                now.row = i+1;
                now.col = j+1;

                q.push(now);
            }
        }
    }
}

int main()
{
    char input[MAX];
    int n;
    int kase = 1;
    int i , j;
    int flag;

    while(cin >> n)
    {
        if(n == 0) break;

        init();
        i = 0;
        flag = 0;

        while(i < n)
        {
            cin >> input;

            for(j = 0 ; input[j] ; j++) board[i+1][j+1] = input[j];
            i++;
        }

        for(i = 1 ; i <= n ; i++)
        {
            if(board[i][1] == white)
            {
                flood_fill(i , 1 , white , red);
            }
        }

        for(i = 1 ; i <= n ; i++)
        {
            if(board[1][i] == black)
            {
                flood_fill(1 , i , black , green);
            }
        }

        for(i = 1 ; i <= n ; i++)
        {
            if(board[i][n] == red)
            {
                cout << kase << ' ' << 'W' << endl;
                kase++;
                flag = 1;
                break;
            }
        }

        if(flag == 0)
        {
            for(i = 1 ; i <= n ; i++)
            {
                if(board[n][i] == red)
                {
                    cout << kase << ' ' << 'B' << endl;
                    kase++;
                    flag = 1;
                    break;
                }
            }
        }
    }

    return 0;
}
