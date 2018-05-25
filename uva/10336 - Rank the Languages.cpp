#include <iostream>
#include <queue>
#include <cctype>
#include <cstdlib>

#define MAX 1000
#define MAX_LANG 128

using namespace std;
typedef int (*compfn)(const void*, const void*);

struct area
{
    int row;
    int col;
};

struct track
{
    char c;
    int count;
};

char blank = ' ';
track ans[MAX_LANG];
char map[MAX][MAX];

int  compare(struct track *a, struct track *b)
{
    if((b->count - a->count) != 0) return(b->count - a->count);
    else return(a->c - b->c);
}

void init(int row,int col)
{
    int i,j;

    for(i = 0; i <= row+1 ; i++)
    {
        for(j = 0 ; j <= col+1 ; j++) map[i][j] = blank;
    }

    for(i = 0 ; i < MAX_LANG ; i++)
    {
        ans[i].c = i;
        ans[i].count = 0;
    }

    return;
}

void flood_fill(int row,int col,char target,char replace)
{
    queue<area> q;
    int i , j;

    if(map[row][col] != target) return;

    area now;
    area west;
    area east;

    now.row = row;
    now.col = col;

    q.push(now);

    while(!q.empty())
    {
        now = q.front();
        q.pop();

        east = now;
        west = now;

        for(i = west.row, j = west.col; map[i][j] == target ; j--);
        west.col = j+1;

        for(i = east.row, j = east.col; map[i][j] == target ; j++);
        east.col = j-1;

        for(i = west.row, j = west.col ; j <= east.col ; j++)
        {
            map[i][j] = replace;

            now.row = i;
            now.col = j;

            if(map[i][j-1] == target)
            {
                now.row = i;
                now.col = j-1;

                q.push(now);
            }

            if(map[i-1][j] == target)
            {
                now.row = i-1;
                now.col = j;

                q.push(now);
            }

            if(map[i+1][j] == target)
            {
                now.row = i+1;
                now.col = j;

                q.push(now);
            }

            if(map[i][j+1] == target)
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
    int kase,cases,height,width,i,j;
    cin >> cases;
    kase = 1;
    char input[MAX];

    while(kase <= cases)
    {
        cin >> height >> width;
        init(height,width);
        i = 0;
        while(i < height)
        {
            cin >> input;
            for(j = 0 ; input[j] ; j++) map[i+1][j+1] = input[j];
            i++;
        }

        for(i = 1 ; i <= height ; i++)
        {
            for(j = 1 ; j <= width ; j++)
            {
                if(isalpha(map[i][j]))
                {
                    ans[map[i][j]].count++;
                    flood_fill(i,j,map[i][j],blank);
                }
            }
        }

        qsort(ans , MAX_LANG , sizeof(struct track) , (compfn)compare);

        cout << "World #" << kase << endl;
        for(i = 0 ; i < MAX_LANG ; i++)
        {
            if(ans[i].count) cout << ans[i].c << ": " << ans[i].count << endl;
        }

        kase++;
        init(height , width);
    }

    return 0;
}
