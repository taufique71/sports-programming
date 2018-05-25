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
char separator = '_';
char null = '\0';
char contour;
char color;

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
    int i,j,max_i = 0;
    char input[MAX_CHAR];

    while(gets(input))
    {
        init();
        i = 0;
        max_i = 0;

        for(j = 0; input[j]; j++) maze[i+1][j+1] = input[j];
        i++;
        if(i > max_i) max_i = i;
        if(input[0] != separator)
        {
            while(gets(input))
            {
                if(input[0] == separator) break;
                for(j = 0; input[j]; j++) maze[i+1][j+1] = input[j];
                i++;
                if(i > max_i) max_i = i;
            }
        }
        for(j = 0; input[j]; j++) maze[i+1][j+1] = input[j];
        i++;
        if(i > max_i) max_i = i;

        int flag = 0;
        for(i = 1 ; i <= max_i ; i++)
        {
            for(j = 1; maze[i][j] != null ; j++)
            {
                if(!isspace(maze[i][j]))
                {
                    contour = maze[i][j];
                    flag = 1;
                    break;
                }
            }
            if(flag == 1) break;
        }

        for(i = 1 ; i < max_i ; i++)
        {
            for(j = 1 ; maze[i][j] != null ; j++)
            {
                if(!isspace(maze[i][j]) && (maze[i][j] != contour))
                {
                    color = maze[i][j];
                    maze[i][j] = blank;
                    flood_fill(i,j,blank,color);
                }
            }
        }

        for(i = 1 ; i <= max_i ; i++)
        {
            for(j = 1 ; maze[i][j] != null ;j++)
            {
                cout << maze[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}
