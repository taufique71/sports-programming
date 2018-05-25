#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <string>
#define MAX 10
using namespace std;

class node
{
public:
    int x;
    int y;
    string s;
}start,end;

class wall
{
public:
    node a;
    node b;
};

bool grid[MAX][MAX];
wall arr[5];
int move[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

bool check(wall r)
{
    int i,j;
    int a,b;
    bool res = true;

    if(r.a.x == r.b.x)
    {
        for(i = 0 ; i < 3 ; i++)
        {
            if(arr[i].a.y == arr[i].b.y)
            {
                if((arr[i].a.x < r.a.x && arr[i].b.x >= r.a.x)||(arr[i].a.x >= r.a.x && arr[i].b.x < r.a.x))
                {
                    if((r.a.y <= arr[i].a.y && r.b.y > arr[i].a.y)||(r.a.y > arr[i].a.y && r.b.y <= arr[i].a.y))
                    {
                        res = false;
                    }
                }
            }
        }
    }
    else
    {
        for(i = 0 ; i < 3 ; i++)
        {
            if(arr[i].a.x == arr[i].b.x)
            {
                if((arr[i].a.y < r.a.y && arr[i].b.y >= r.a.y)||(arr[i].a.y >= r.a.y && arr[i].b.y < r.a.y))
                {
                    if((r.a.x <= arr[i].a.x && r.b.x > arr[i].a.x)||(r.a.x > arr[i].a.x && r.b.x <= arr[i].a.x))
                    {
                        res = false;
                    }
                }
            }
        }
    }
    return res;
}

int main()
{
    int i,j;
    int a,b;

    while(cin >> start.x >> start.y)
    {
        if(start.x == 0 && start.y == 0) break;

        //memset(grid,true,sizeof(grid));

        for(i = 0 ; i < MAX ; i++)
        {
            for(j = 0 ; j < MAX ; j++) grid[i][j] = true;
        }

        cin >> end.x >> end.y;
        cin >> arr[0].a.x >> arr[0].a.y >> arr[0].b.x >> arr[0].b.y;
        //arr[0].a.x--; arr[0].a.y--; arr[0].b.x--; arr[0].b.y--;
        cin >> arr[1].a.x >> arr[1].a.y >> arr[1].b.x >> arr[1].b.y;
        //arr[1].a.x--; arr[1].a.y--; arr[1].b.x--; arr[1].b.y--;
        cin >> arr[2].a.x >> arr[2].a.y >> arr[2].b.x >> arr[2].b.y;
        //arr[2].a.x--; arr[2].a.y--; arr[2].b.x--; arr[2].b.y--;

        queue<node> q;
        node front,temp;
        int temp_x,temp_y;
        start.s = "";
        end.s = "";
        bool flag = true;
        q.push(start);
        grid[start.y][start.x] = false;

        while(!q.empty() && flag)
        {
            front = q.front();
            q.pop();

            for(i = 0 ; i < 4 ; i++)
            {
                temp_x = front.x + move[i][0];
                temp_y = front.y + move[i][1];

                if(temp_x >= 1 && temp_y >= 1 && temp_x <= 6 && temp_y <= 6 && grid[temp_y][temp_x] == true)
                {
                    wall route;
                    route.a = front;
                    route.b.x = temp_x;
                    route.b.y = temp_y;

                    if(check(route))
                    {
                        grid[temp_y][temp_x] = false;

                        temp.x = temp_x;
                        temp.y = temp_y;

                        if(i == 0) temp.s = front.s + "E";
                        else if(i == 1) temp.s = front.s + "W";
                        else if(i == 2) temp.s = front.s + "S";
                        else if(i == 3) temp.s = front.s + "N";

                        q.push(temp);

                        if(temp_x == end.x && temp_y == end.y)
                        {
                            end.s = temp.s;
                            flag = false;
                            break;
                        }
                    }
                }
            }
        }

        cout << end.s << endl;
    }

    return 0;
}
