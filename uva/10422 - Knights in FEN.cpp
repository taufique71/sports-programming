#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <queue>
#include <map>
using namespace std;

class state
{
public:
    char board[5][6];
    int i,j;
    int step;

    void init(int ii,int jj,int s,char b[5][6])
    {
        for(int a = 0 ; a < 5 ; a++) strcpy(board[a],b[a]);
        i = ii;
        j = jj;
        step = s;
    }
};

int move[8][2] = {{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
map<string,bool> color;
string final = "111110111100 110000100000";

int judge(state s)
{
    string str = "";
    int i,j;

    for(i = 0 ; i < 5 ; i++) str += s.board[i];

    if(str == final) return 1;
    else if(color[str] == true) return 2;
    color[str] = true;
    return 3;
}

int main()
{
    int t;
    int i,j,ti,tj;
    state start,next;

    scanf("%d",&t);
    getchar();
    char board[5][6];

    while(t--)
    {
        color.clear();
        for(i = 0 ; i < 5 ; i++)
        {
            for(j = 0 ; j < 5 ; j++)
            {
                board[i][j] = getchar();
                if(board[i][j] == ' ')
                {
                    ti = i;
                    tj = j;
                }
            }
            getchar();
            board[i][j] = '\0';
        }

        start.init(ti,tj,0,board);
        bool flag = true;
        queue<state> q;
        int res = judge(start);

        if(res == 1)
        {
            printf("Solvable in 0 move(s).\n");
            continue;
        }
        else q.push(start);

        while(!q.empty())
        {
            start = q.front();
            q.pop();
            for(i = 0 ; i < 8 ; i++)
            {
                ti = start.i + move[i][0];
                tj = start.j + move[i][1];

                if(ti >= 0 && tj >= 0 && ti < 5 && tj < 5)
                {
                    next.init(ti,tj,start.step+1,start.board);
                    next.board[start.i][start.j] = start.board[ti][tj];
                    next.board[ti][tj] = ' ';

                    res = judge(next);

                    if(next.step > 10)
                    {
                        printf("Unsolvable in less than 11 move(s).\n");
                        flag = false;
                        break;
                    }
                    else if(res == 1)
                    {
                        printf("Solvable in %d move(s).\n",next.step);
                        flag = false;
                        break;
                    }
                    else if(res == 3)
                    {
                        q.push(next);
                    }
                }
            }

            if(flag == false) break;
        }
    }

    return 0;
}
