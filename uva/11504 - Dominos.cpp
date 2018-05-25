#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define MAX 100000
using namespace std;

vector<int> g[MAX+10];
vector<int> gt[MAX+10];
vector<int> order;
bool color[MAX+10];
int component[MAX+10];
int indegree[MAX+10];

int m,n;

void preset()
{
    int i,j;
    for(i = 0 ; i < MAX+10 ; i++)
    {
        g[i].clear();
        gt[i].clear();
    }
    memset(color,true,sizeof(color));
    memset(indegree,0,sizeof(indegree));
}

void dfsg(int a)
{
    int i,j;
    color[a] = false;

    //cout << "visiting " << a << endl;

    for(i = 0 ; i < g[a].size() ; i++) if(color[g[a][i]]) dfsg(g[a][i]);
    order.push_back(a);

    //cout << "exiting " << a << endl;
}

void dfsgt(int a,int c)
{
    //cout << "dfsgt visiting " << a << " with component no " << c << endl;
    int i,j;
    color[a] = true;
    component[a] = c;

    for(i = 0 ; i < gt[a].size() ; i++)
    {
        if(!color[gt[a][i]])
        {
            dfsgt(gt[a][i],c);
        }
    }
    //cout << "dfsgt exiting " << a << " with component no " << c << endl;
}

int main()
{
    int n_case;
    int i,j;
    int a,b;
    scanf("%d",&n_case);

    while(n_case--)
    {
        scanf("%d %d",&n,&m);

        preset();

        for(i = 1 ; i <= m ; i++)
        {
            scanf("%d %d",&a,&b);
            g[a].push_back(b);
            gt[b].push_back(a);
        }

        for(i = 1 ; i <= n ; i++) if(color[i]) dfsg(i);

        int n_component = 0;

        for(i = order.size()-1 ; i >= 0 ; i--)
        {
            //cout << i << ' ' << order[i] << ' ';
            if(!color[order[i]])
            {
                dfsgt(order[i],n_component++);
            }
            //cout << i << endl;
        }

        for(i = 1 ; i <= n ; i++)
        {
            for(j = 0 ; j < g[i].size() ; j++)
            {
                if(component[i] != component[g[i][j]]) indegree[component[g[i][j]]]++;
            }
        }

        int count = 0;
        for(i = 0 ; i < n_component ; i++)
        {
            if(indegree[i] == 0) count++;
        }
        cout << count << endl;
    }
}
