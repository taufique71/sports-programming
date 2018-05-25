#include <iostream>
#include <cstdio>
#include <queue>
#include <iomanip>
#define MAX 25
using namespace std;

bool map[MAX][MAX];
bool color[MAX];
int cnt[MAX];

int bfs(int a,int b)
{
    for(int i = 0 ; i < MAX ; i++)
    {
        color[i] = true;
        cnt[i] = 0;
    }
    queue<int> q;
    q.push(a);
    color[a] = false;
    while(!q.empty())
    {
        a = q.front();
        q.pop();
        for(int i = 0 ; i < 20 ; i++)
        {
            if(map[a][i] == true)
            {
                if(color[i] == true)
                {
                    color[i] = false;
                    q.push(i);
                    cnt[i] = cnt[a]+1;
                }
            }
        }
    }

    return cnt[b];
}

int main()
{
    int n,a,b;
    int i,j,k;
    int n_case = 1;
    while(scanf("%d",&n) != EOF)
    {
        i = 0;
        for(j = 0 ; j < MAX ; j++)
        {
            for(k = 0 ; k < MAX ; k++) map[j][k] = false;
        }

        while(n--)
        {
            scanf("%d",&a);
            map[i][a-1] = true;
            map[a-1][i] = true;
        }
        i++;
        while(i < 19)
        {
            scanf("%d",&n);
            while(n--)
            {
                scanf("%d",&a);
                map[i][a-1] = true;
                map[a-1][i] = true;
            }
            i++;
        }

        scanf("%d",&n);
        printf("Test Set #%d\n",n_case);
        while(n--)
        {
            scanf("%d %d",&a,&b);
            cout << right;
            cout << setw(2);
            cout << a;
            cout << " to ";
            cout << right;
            cout << setw(2);
            cout << b;
            cout << ": ";
            cout << bfs(a-1,b-1) << endl;
        }
        cout << endl;
        n_case++;
    }
    return 0;
}
