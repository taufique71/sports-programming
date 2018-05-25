#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#define MAX 110
using namespace std;

class node
{
public:
    double x;
    double y;
    double w;
    int i;

    const bool operator>(const node &p) const
    {
        if(this->w > p.w) return true;
        else return false;
    }

    const bool operator<(const node &p) const
    {
        if(this->w < p.w) return true;
        else return false;
    }
};

int n_nodes;
bool color[MAX];
int pred[MAX];
node arr[MAX];
bool graph[MAX][MAX];
bool result[MAX][MAX];
double weight[MAX][MAX];
const double inf = 123698745;

double dist(node a,node b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main()
{
    int n_case;
    int i,j;
    node temp;
    bool flag = false;

    cin >> n_case;

    while(n_case--)
    {
        cin >> n_nodes;
        memset(color,true,sizeof(color));
        memset(graph,true,sizeof(graph));
        memset(pred,-1,sizeof(pred));

        priority_queue< node,vector<node>,greater<node> > pq;

        for(i = 0 ; i < n_nodes ; i++)
        {
            arr[i].i = i;
            cin >> arr[i].x >> arr[i].y;
            if(i == 0) arr[i].w = 0;
            else arr[i].w = inf;

            pq.push(arr[i]);
        }

        for(i = 0 ; i < n_nodes ; i++)
        {
            for(j = 0 ; j < n_nodes ; j++)
            {
                weight[i][j] = dist(arr[i],arr[j]);
                weight[j][i] = weight[i][j];
            }
        }

        while(!pq.empty())
        {
            temp = pq.top();
            pq.pop();
            color[temp.i] = false;
            for(i = 0 ; i < n_nodes ; i++)
            {
                if(graph[temp.i][i])
                {
                    if(color[i] == true)
                    {
                        if(weight[temp.i][i] < arr[i].w)
                        {
                            arr[i].w = weight[temp.i][i];
                            pred[i] = temp.i;
                            pq.push(arr[i]);
                        }
                    }
                }
            }
        }

        double ans = 0;
        for(i= 0 ; i < n_nodes ; i++) if(pred[i] >= 0) ans += weight[i][pred[i]];
        if(flag == true) cout << endl;
        printf("%0.2lf\n",ans);
        flag = true;
    }
    return 0;
}
