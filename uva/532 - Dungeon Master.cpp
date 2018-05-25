#include <iostream>
#include <cstdio>
#include <queue>
#define MAX 35
using namespace std;

class block
{
public:
    int i;
    int j;
    int k;
    int c;

    block()
    {
        c = 0;
        return;
    }
}s,e;

char input[MAX][MAX][MAX];

int bfs()
{
    block p,t;
    queue<block> q;
    int c = 0;

    q.push(s);
    input[s.i][s.j][s.k] = '*';

    while(!q.empty())
    {
        p = q.front();
        q.pop();
        //cout << "level : " << p.i << " row : " << p.j << " column : " << p.k << " cost : " << p.c << endl;

        if(input[p.i-1][p.j][p.k] != '#' && input[p.i-1][p.j][p.k] != '*')
        {
            t.i = p.i-1;
            t.j = p.j;
            t.k = p.k;
            input[t.i][t.j][t.k] = '*';
            c = p.c + 1;
            t.c = c;
            if(t.i == e.i && t.j == e.j && t.k == e.k) break;
            q.push(t);
        }

        if(input[p.i+1][p.j][p.k] != '#' && input[p.i+1][p.j][p.k] != '*')
        {
            t.i = p.i+1;
            t.j = p.j;
            t.k = p.k;
            input[t.i][t.j][t.k] = '*';
            c = p.c + 1;
            t.c = c;
            if(t.i == e.i && t.j == e.j && t.k == e.k) break;
            q.push(t);
        }

        if(input[p.i][p.j-1][p.k] != '#' && input[p.i][p.j-1][p.k] != '*')
        {
            t.i = p.i;
            t.j = p.j-1;
            t.k = p.k;
            input[t.i][t.j][t.k] = '*';
            c = p.c + 1;
            t.c = c;
            if(t.i == e.i && t.j == e.j && t.k == e.k) break;
            q.push(t);
        }

        if(input[p.i][p.j+1][p.k] != '#' && input[p.i][p.j+1][p.k] != '*')
        {
            t.i = p.i;
            t.j = p.j+1;
            t.k = p.k;
            input[t.i][t.j][t.k] = '*';
            c = p.c + 1;
            t.c = c;
            if(t.i == e.i && t.j == e.j && t.k == e.k) break;
            q.push(t);
        }

        if(input[p.i][p.j][p.k-1] != '#' && input[p.i][p.j][p.k-1] != '*')
        {
            t.i = p.i;
            t.j = p.j;
            t.k = p.k-1;
            input[t.i][t.j][t.k] = '*';
            c = p.c + 1;
            t.c = c;
            if(t.i == e.i && t.j == e.j && t.k == e.k) break;
            q.push(t);
        }

        if(input[p.i][p.j][p.k+1] != '#' && input[p.i][p.j][p.k+1] != '*')
        {
            t.i = p.i;
            t.j = p.j;
            t.k = p.k+1;
            input[t.i][t.j][t.k] = '*';
            c = p.c + 1;
            t.c = c;
            if(t.i == e.i && t.j == e.j && t.k == e.k) break;
            q.push(t);
        }
    }
    if(input[e.i][e.j][e.k] == '*') return c;
    else return 0;
}

int main()
{
    int L,R,C;
    int i,j,k;
    while(scanf("%d %d %d",&L,&R,&C) == 3)
    {
        if(L == 0 && R == 0 && C == 0) break;
        for(i = 0 ; i <= L+1 ; i++)
        {
            for(j = 0 ; j <= R+1 ; j++)
            {
                for(k = 0 ; k <= C+1 ; k++)
                {
                    if(i == 0 || j == 0 || k == 0) input[i][j][k] = '#';
                    else if(i == L+1 || j == R+1 || k == C+1) input[i][j][k] = '#';
                    else
                    {
                        cin >> input[i][j][k];
                        if(input[i][j][k] == 'E')
                        {
                            e.i = i;e.j = j;e.k = k;
                            //cout << "end : " << i << ',' << j << ',' << k << ' '<< endl;
                        }
                        else if(input[i][j][k] == 'S')
                        {
                            s.i = i;s.j = j;s.k = k;
                            //cout << "start : " << i << ',' << j << ',' << k << ' '<< endl;
                        }
                    }
                }
            }
        }

        //printf("%d,%d,%d %d,%d,%d\n",s.i,s.j,s.k,e.i,e.j,e.k);

        int r = bfs();
        if(r != 0) printf("Escaped in %d minute(s).\n",r);
        else printf("Trapped!\n");
    }
    return 0;
}
