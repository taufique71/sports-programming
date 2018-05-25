#include <iostream>
#include <queue>
#include <vector>
#define MAX_NODE 11
using namespace std;

class node
{
public:
    int weight;
    int n;
    int color;

    const bool operator>(const node &p) const
    {
        if(this->weight > p.weight) return true;
        else return false;
    }
    const bool operator<(const node &p) const
    {
        if(this->weight < p.weight) return true;
        else return false;
    }
};

int graph[MAX_NODE][MAX_NODE];
node calculation[MAX_NODE];
int shortest_path[MAX_NODE];
const int infinity = 2147483647;
int white = 0;
int blue = 1;

void init()
{
    for(int i = 0; i < MAX_NODE ; i++)
    {
        for(int j = 0 ; j < MAX_NODE ; j++)
        {
            graph[i][j] = 0;
        }
        calculation[i].n = i;
        calculation[i].color = white;
        calculation[i].weight = infinity;
        shortest_path[i] = 0;
    }
}

void dijkstra(int start)
{
    priority_queue< node,vector<node>,greater<node> > q;
    calculation[start].weight = 0;
	q.push(calculation[start]);

	node temp;
	int i,j;

	while(q.size() != 0)
	{
		temp = q.top();
		q.pop();
        if(calculation[temp.n].weight == temp.weight && calculation[temp.n].color == white)
        {
            calculation[temp.n].color = blue;
            for(i = 1 ; i < MAX_NODE ; i++)
            {
                if(graph[temp.n][i])
                {
                    if(calculation[temp.n].weight+graph[temp.n][i] < calculation[i].weight)
                    {
                        calculation[i].weight = calculation[temp.n].weight+graph[temp.n][i];
                        shortest_path[i] = temp.n;
                        q.push(calculation[i]);
                    }
                }
            }
        }
	}
}

void path(int n_case, int start, int end)
{
    vector<int> arr;

    int i = end;
    int delay = 0;
    arr.push_back(i);
    while(i!=start)
    {
        delay += graph[shortest_path[i]][i];
        i=shortest_path[i];
        arr.push_back(i);
    }
    printf("Case %d: Path =",n_case);
    for(i = arr.size()-1 ; i >= 0 ; i--) cout << ' ' << arr[i];
    printf("; %d second delay\n",delay);
}

int main()
{
    int n_nodes;
    int n_away_nodes;
    int away_node,weight;
    int i,j;
    int n_case = 1;
    int start,end;

    while(cin >> n_nodes)
    {
        if(n_nodes == 0) break;
        init();
        for(i = 1 ; i <= n_nodes; i++)
        {
            cin >> n_away_nodes;
            for(j = 1 ; j <= n_away_nodes ; j++)
            {
                cin >> away_node >> weight;
                graph[i][away_node] = weight;
            }
        }
        cin >> start >> end;
        dijkstra(start);
        path(n_case,start,end);
        n_case++;
    }

    return 0;
}
