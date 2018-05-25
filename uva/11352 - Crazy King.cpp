#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#define MAX 110
using namespace std;

class node
{
public:
    int r;
    int c;
}start,end;

bool grid[MAX][MAX];
int cnt[MAX][MAX];
int move_h[8][2] = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
int move_k[8][2] = {{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1}};
vector<node> horse;

int main()
{
    int t;
    int i,j;
    int row,col;
    int temp_r,temp_c;
    char input;

    cin >> t;

    while(t--)
    {
        cin >> row >> col;

        for(i = 0 ; i < MAX ; i++)
        {
            for(j = 0 ; j < MAX ; j++)
            {
                grid[i][j] = true;
                cnt[i][j] = 0;
            }
        }
        horse.clear();

        for(i = 0 ; i < row ; i++)
        {
            for(j = 0  ; j < col ; j++)
            {
                cin >>  input;
                if(input == 'Z')
                {
                    horse.push_back((node){i,j});
                    grid[i][j] = false;
                }
                else if(input == 'A')
                {
                    start.r = i;
                    start.c = j;
                }
                else if(input == 'B')
                {
                    end.r = i;
                    end.c = j;
                }
            }
        }

        for(i = 0 ; i < horse.size() ; i++)
        {
            for(j = 0 ; j < 8 ; j++)
            {
                temp_r = horse[i].r + move_h[j][0];
                temp_c = horse[i].c + move_h[j][1];

                if(temp_r >= 0 && temp_c >= 0 && temp_r < row && temp_c < col)
                {
                    if(temp_r == end.r && temp_c == end.c) grid[temp_r][temp_c] = true;
                    else  grid[temp_r][temp_c] = false;
                }
            }
        }

        queue<node> q;
        bool flag = true;
        node front;
        q.push(start);
        grid[start.r][start.c] = false;

        while(!q.empty() && flag)
        {
            front = q.front();
            q.pop();

            for(i = 0 ; i < 8 ; i++)
            {
                temp_r = front.r + move_k[i][0];
                temp_c = front.c + move_k[i][1];

                if(temp_r >= 0 && temp_c >= 0 && temp_r < row && temp_c < col)
                {
                    if(grid[temp_r][temp_c] == true)
                    {
                        q.push((node){temp_r,temp_c});
                        cnt[temp_r][temp_c] = cnt[front.r][front.c] + 1;
                        grid[temp_r][temp_c] = false;
                        {
                            if(temp_r == end.r && temp_c == end.c)
                            {
                                flag = false;
                                break;
                            }
                        }
                        //printf("from %d,%d to %d,%d\n",front.r,front.c,temp_r,temp_c);
                    }
                }
            }
        }

        if(grid[end.r][end.c] == true) printf("King Peter, you can't go now!\n");
        else printf("Minimal possible length of a trip is %d\n",cnt[end.r][end.c]);
    }

    return 0;
}
