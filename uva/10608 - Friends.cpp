#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 30010
using namespace std;

int parent[MAX];
int size[MAX];

int find_parent(int n)
{
    if(parent[n] == n) return n;
    else return parent[n] = find_parent(parent[n]);
}

int main()
{
    int n,m;
    int t;
    int i,j;
    int a,b;
    int p,q;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d",&n,&m);

        for(i = 0 ; i <= n ; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }

        for(i = 0 ; i < m ; i++)
        {
            scanf("%d %d",&a,&b);
            a--;
            b--;

            p = find_parent(a);
            q = find_parent(b);

            if(p != q)
            {
                if(size[p] > size[q]) swap(p,q);
                size[q] += size[p];
                parent[p] = q;
            }
        }
        int max = size[0];
        for(i = 0 ; i < n ; i++)
        {
            if(size[i] > max) max = size[i];
        }
        printf("%d\n",max);
    }

    return 0;
}
