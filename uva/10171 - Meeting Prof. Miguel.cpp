#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#define MAX 30
#define inf 10 << 27
using namespace std;

class node
{
public:
    int no;
    int cost;

    bool operator<(const node& a) const
    {
        return (this->cost > a.cost);
    }
};

vector<node> list_y[MAX];
vector<node> list_m[MAX];
int cost_y[MAX];
int cost_m[MAX];
int result[MAX];

int max(int a,int b)
{
    if(a >= b) return a;
    else return b;
}

int main()
{
    int N;
    int i,j;
    char age,dir,from,to;
    char manzoor,miguel;
    int w;

    while(scanf("%d",&N) && N)
    {
        for(i = 0; i < MAX ; i++)
        {
            list_y[i].clear();
            list_m[i].clear();
            cost_m[i] = inf;
            cost_y[i] = inf;
        }

        for(i = 0 ; i < N ; i++)
        {
            cin >> age >> dir >> from >> to >> w;
            if(age == 'Y')
            {
                if(dir == 'B')
                {
                    list_y[from-'A'].push_back((node){to-'A',w});
                    list_y[to-'A'].push_back((node){from-'A',w});
                }
                else
                {
                    list_y[from-'A'].push_back((node){to-'A',w});
                }
            }
            else
            {
                if(dir == 'B')
                {
                    list_m[from-'A'].push_back((node){to-'A',w});
                    list_m[to-'A'].push_back((node){from-'A',w});
                }
                else
                {
                    list_m[from-'A'].push_back((node){to-'A',w});
                }
            }
        }

        cin >> manzoor >> miguel;

        node front;
        int next,next_d;

        priority_queue<node> pq_y;
        priority_queue<node> pq_m;

        cost_y[manzoor-'A'] = 0;
        pq_y.push((node){manzoor-'A',0});

        while(!pq_y.empty())
        {
            front = pq_y.top();
            pq_y.pop();

            if(cost_y[front.no] != front.cost) continue;
            for(i = 0 ; i < list_y[front.no].size() ; i++)
            {
                next = list_y[front.no][i].no;
                next_d = cost_y[front.no] + list_y[front.no][i].cost;
                if(next_d < cost_y[next])
                {
                    cost_y[next] = next_d;
                    pq_y.push((node){next,next_d});
                }
            }
        }

        cost_m[miguel-'A'] = 0;
        pq_m.push((node){miguel-'A',0});

        while(!pq_m.empty())
        {
            front = pq_m.top();
            pq_m.pop();

            if(cost_m[front.no] != front.cost) continue;
            for(i = 0 ; i < list_m[front.no].size() ; i++)
            {
                next = list_m[front.no][i].no;
                next_d = cost_m[front.no] + list_m[front.no][i].cost;
                if(next_d < cost_m[next])
                {
                    cost_m[next] = next_d;
                    pq_m.push((node){next,next_d});
                }
            }
        }

        char place;
        int cost = inf;

        for(i = 0 ; i < MAX ; i++)
        {
            if(cost_y[i] != inf && cost_m[i] != inf) result[i] = cost_y[i] + cost_m[i];
            else result[i] = inf;

            if(result[i] < cost)
            {
                cost = result[i];
                place = 'A' + i;
            }
        }

        if(cost != inf)
        {
            printf("%d",cost);
            for(i = 0 ; i < MAX ; i++)
            {
                if(cost == result[i]) printf(" %c",i+'A');
            }
            cout << endl;
        }
        else printf("You will never meet.\n");
    }
    return 0;
}
