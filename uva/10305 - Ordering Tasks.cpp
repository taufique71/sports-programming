#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 110
using namespace std;

class node
{
public:
    int f;
    int l;
    int i;
};

bool color[MAX];
node nods[MAX];
bool graph[MAX][MAX];
int n,m;
int t;

bool compare(node a,node b)
{
    if(a.l > b.l) return true;
    else return false;
}

void dfs(int i)
{
    color[i] = false;
    nods[i].f = t++;

    for(int j = 0 ; j <= n ; j++)
    {
        if(graph[i][j] == true && color[j] == true)
        {
            dfs(j);
        }
    }
    nods[i].l = t++;
}

int main()
{
    int i,j;
    int a,b;

    while(cin >> n >> m)
    {
        if(n == 0 &&  m == 0) break;

        memset(color,true,sizeof(color));
        memset(graph,false,sizeof(graph));

        for(i = 0 ; i < MAX ; i++)
        {
            nods[i].i = i;
            nods[i].f = -1;
            nods[i].l = -1;
        }

        for(i = 0 ; i < m ; i++)
        {
            cin >> a >> b;
            graph[a][b] = true;
        }

        t = 0;

        for(i = 1 ; i <= n ; i++)
        {
            if(color[i] == true)
            {
                dfs(i);
            }
        }
        sort(nods,nods+MAX,compare);
        //for(i = 0 ; i <= n ; i++) cout << nods[i].i << ',' << nods[i].f << ',' << nods[i].l << endl;
        //cout << endl;

        for(i = 0 ; i < n && nods[i].l >= 0 ; i++)
        {
            cout << nods[i].i ;
            if(n-i > 1) cout << ' ';
        }
        cout << endl;
    }
    return 0;
}
