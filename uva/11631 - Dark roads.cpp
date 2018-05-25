#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 200010
using namespace std;

struct edge
{
    int u;
    int v;
    int w;
}e[200010];

int size[200010];
int parent[200010];

bool cmp(edge a, edge b)
{
    if(a.w < b.w) return true;
    else return false;
}

int find_parent(int n)
{
    if(parent[n] == n) return n;
    else return parent[n] = find_parent(parent[n]);
}

int main()
{
    int m,n;
    int i,j;
    int p,q;
    int total;

    while(scanf("%d %d",&m,&n))
    {
        if(m == 0 && n == 0) break;

        total = 0;
        for(i = 0 ; i < n ; i++)
        {
            scanf("%d %d %d",&e[i].u,&e[i].v,&e[i].w);
            parent[i] = i;
            size[i] = 1;
            total += e[i].w;
        }

        parent[n] = n;
        size[n] = 1;

        sort(e,e+n,cmp);
        int taken = m-1;
        int count = 0;

        for(i = 0 ; i < n && taken; i++)
        {
            p = find_parent(e[i].u);
            q = find_parent(e[i].v);

            if(p != q)
            {
                if(size[q] > size[p]) swap(p,q);
                size[p] += size[q];
                parent[q] = p;
                count += e[i].w;
                taken--;
            }
        }

        printf("%d\n",total-count);
    }
    return 0;
}
