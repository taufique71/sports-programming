#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define MAX 1000
using namespace std;

class point
{
public:
    int x,y;
}start,end,temp;

bool grid[MAX][MAX];
int step[MAX][MAX];
int move[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

int main()
{
    int r,c,n_line,a,b,n;
    int i,j;

    while(cin >> r >> c)
    {
        if(r == 0 && c == 0) break;
        memset(grid,true,sizeof(grid));

        cin >> n_line;
        for(i = 0 ; i < n_line ; i++)
        {
            cin >> a >> n;
            for(j = 0 ; j < n ; j++)
            {
                cin >> b;
                grid[a][b] = false;
            }
        }

        cin >> start.x >> start.y;
        cin >> end.x >> end.y;

        /*for(i = 0 ; i < r ; i++)
        {
            for(j = 0 ; j < c ; j++) cout << grid[i][j];
            cout << endl;
        }*/

        queue<point> q;
        q.push(start);
        grid[start.x][start.y] = false;
        step[start.x][start.y] = 0;

        bool flag = true;

        while(!q.empty())
        {
            start = q.front();
            q.pop();

            int ti,tj;
            for(i = 0 ; i < 4 ; i++)
            {
                ti = start.x + move[i][0];
                tj = start.y + move[i][1];

                if(ti >= 0 && ti < r && tj >= 0 && tj < c)
                {
                    temp.x = ti;
                    temp.y = tj;

                    if(grid[temp.x][temp.y] == true)
                    {
                        grid[temp.x][temp.y] = false;
                        step[temp.x][temp.y] = step[start.x][start.y] + 1;
                        q.push(temp);
                        if(temp.x == end.x && temp.y == end.y)
                        {
                            flag = false;
                            break;
                        }
                    }
                }
            }
            if(flag == false) break;
        }

        printf("%d\n",step[end.x][end.y]);

        /*for(i = 0 ; i < r ; i++)
        {
            for(j = 0 ; j < c ; j++) cout << grid[i][j];
            cout << endl;
        }*/
    }
    return 0;
}
