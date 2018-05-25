#include <iostream>
#include <queue>

#define MAX_LINE 50
#define MAX_CHAR 100

using namespace std;

struct grid
{
    int row;
    int col;
};

char maze[MAX_LINE][MAX_CHAR];
char track[MAX_LINE][MAX_CHAR];
char blank = ' ';
char star = '*';
char separator = '_';
char color = '#';
char null = '\0';

void init()
{
    int i,j;

    for(i = 0 ; i < MAX_LINE ; i++)
    {
        for(j = 0 ; j < MAX_CHAR ; j++) maze[i][j] = null;
    }
}

void flood_fill(int row,int col,char target,char replace)
{
    queue<grid> q;
    int i , j;

    if(maze[row][col] != target) return;

    grid now;
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

        for(i = west.row, j = west.col; maze[i][j] == target ; j--);
        west.col = j+1;

        for(i = east.row, j = east.col; maze[i][j] == target ; j++);
        east.col = j-1;

        for(i = west.row, j = west.col ; j <= east.col ; j++)
        {
            maze[i][j] = replace;

            now.row = i;
            now.col = j;

            if(maze[i][j-1] == target)
            {
                now.row = i;
                now.col = j-1;

                q.push(now);
            }

            if(maze[i-1][j] == target)
            {
                now.row = i-1;
                now.col = j;

                q.push(now);
            }

            if(maze[i+1][j] == target)
            {
                now.row = i+1;
                now.col = j;

                q.push(now);
            }

            if(maze[i][j+1] == target)
            {
                now.row = i;
                now.col = j+1;

                q.push(now);
            }
        }
    }
}

int main()
{
    int kase;
    char gar[10];
    cin >> kase;
    gets(gar);

    while(kase--)
    {
        int max_j = 0 , star_i = 0;
        int max_i = 0 , star_j = 0;
        int i,j;
        char input[MAX_CHAR];

        init();

        i = 0;
        while(gets(input))
        {
            if(input[0] == separator) break;
            for(j = 0 ; input[j] ; j++)
            {
                maze[i+1][j+1] = input[j];
                if(input[j] == star)
                {
                    star_i = i+1;
                    star_j = j+1;
                    maze[star_i][star_j] = blank;
                }
            }
            if(j > max_j) max_j = j;
            if(i > max_i) max_i = i;
            i++;
        }
        for(j = 0 ; input[j] ; j++) maze[i+1][j+1] = input[j];
        i++;
        if(j > max_j) max_j = j;
        if(i > max_i) max_i = i;

        flood_fill(star_i,star_j,blank,color);

        for(i = 1;i <= max_i;i++)
        {
            for(j = 1;(j <= max_j)&&(maze[i][j] != null) ; j++) cout << maze[i][j];
            cout << endl;
        }
    }

    //while(1);

    return 0;
}
