#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
#include <vector>
#define MAX 100
#define inf 10 << 27
using namespace std;

class node
{
public:
    int now;
    int cost;

    bool operator<(const node& a)const
    {
        return (this->cost > a.cost);
    }
};

int C,R,Q;
int city[MAX];
int result[MAX][MAX];
vector<node> list[MAX];

int min(int a,int b)
{
    if(a < b) return a;
    else return b;
}

void calculate(int s,int limit)
{
    if(city[s] > limit) return;

    int d[MAX];
    node front;
    int next;
    int next_d;
    int i,j;

    for(i = 0 ; i < C ; i++) d[i] = inf;
    d[s] = 0;

    priority_queue<node> pq;
    pq.push((node){s,0});

    while(!pq.empty())
    {
        front = pq.top();
        pq.pop();

        if(d[front.now] != front.cost) continue;

        for(i = 0 ; i < list[front.now].size() ; i++)
        {
            next = list[front.now][i].now;
            next_d = list[front.now][i].cost + d[front.now];
            if(city[next] > limit) continue;
            if(next_d < d[next])
            {
                d[next] = next_d;
                pq.push((node){next,next_d});
            }
        }
    }

    for(i = 0 ; i < C ; i++)
    {
        result[s][i] = min(result[s][i],d[i]+limit);
    }
}

void solve()
{
    int i,j;

    for(i = 0 ; i < C ; i++)
    {
        for(j = 0 ; j < C ; j++)
        {
            calculate(i,city[j]);
        }
    }
}

int main()
{
    int i,j,a,b,c;
    int t = 1;
    bool flag = false;

    while(cin >> C >> R >> Q)
    {
        if(C == 0 && R == 0 && Q == 0) break;

        for(i = 0 ; i < C ; i++)
        {
            cin >> city[i];
            list[i].clear();
        }

        for(i = 0 ; i < C ; i++)
        {
            for(j = 0 ; j < C ; j++)
            {
                if(i != j) result[i][j] = inf;
                else result[i][j] = city[i];
            }
        }

        for(i = 0 ; i < R ; i++)
        {
            cin >> a >> b >> c;
            a--;
            b--;
            list[a].push_back((node){b,c});
            list[b].push_back((node){a,c});
        }

        /*for(i = 0 ; i < C ; i++)
        {
            for(j = 0 ; j < C ; j++)
            {
                if(result[i][j] == inf) cout << "inf\t";
                else cout << result[i][j] << '\t';
            }
            cout << endl;
        }*/

        solve();

        /*cout << endl;
        for(i = 0 ; i < C ; i++)
        {
            for(j = 0 ; j < C ; j++)
            {
                if(result[i][j] == inf) cout << "inf\t";
                else cout << result[i][j] << '\t';
            }
            cout << endl;
        }*/

        if(flag == true) cout << endl;
        printf("Case #%d\n",t);
        for(i = 0 ; i < Q ; i++)
        {
            cin >> a >> b;
            a--;
            b--;
            if(result[a][b] < inf) cout << result[a][b] << endl;
            else cout << -1 << endl;
        }
        t++;
        flag = true;
    }
    return 0;
}
