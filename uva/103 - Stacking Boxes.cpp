#include <iostream>
#include <vector>

#define MAX_DIM 10
#define MAX_BOX 30

using namespace std;

struct node
{
    int color;
    int label_in;
    int label_out;
    int serial_no;
};

int boxes[MAX_BOX][MAX_DIM];
int graph[MAX_BOX][MAX_BOX];
node nodes[MAX_BOX];

vector<int> topology;
vector<int> next;
vector<int> times;
vector<int> result;

int n_box , n_dim;

int white = 0;
int gray = 1;
int black = 2;
int num = 0;

int compare_dim (const void * a, const void * b);
int is_nest(int a,int b);
void create_graph();
void dfs_visit(int i);
void dfs();
void calculate();
void print_graph();

int main()
{
    int i , j ;

    while(cin >> n_box >> n_dim)
    {
        i = 0;
        num = 0;
        while(i < n_box)        //Takes input
        {
            j = 0;
            while(j < n_dim)
            {
                cin >> boxes[i][j];
                j++;
            }
            qsort(boxes[i] , n_dim , sizeof(int), compare_dim);     // Sorts the dimensions of the boxes.
            i++;
        }

        create_graph(); //Creates Graph from the nodes. Draw the edges

        dfs();

        calculate();
    }

    return 0;
}

int compare_dim (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

int is_nest(int a,int b)
{
    int i;

    for(i = n_dim - 1 ; (i >=0) ; i--)
    {
        if(boxes[a][i] <= boxes[b][i]) return 0;
    }

    return 1;
}

void create_graph()
{
    int i , j;

    for(i = 0 ; i < MAX_BOX ; i++)
    {
        for(j = 0 ; j < MAX_BOX ; j++) graph[i][j] = 0;
    }

    for(i = 0 ; i < n_box ; i++)
    {
        for(j = 0 ; j < n_box ; j++)
        {
            if(i != j)
            {
                if(graph[j][i] != 1)
                {
                    if(is_nest(i , j)) graph[i][j] = 1;
                }
            }
        }
    }
}

void dfs_visit(int i)       //DFS traverse
{
    int j;

    nodes[i].color = gray;
    num++;
    nodes[i].label_in = num;

    for(j = 0 ; j < n_box ; j++)
    {
        if(graph[i][j] == 1)
        {
            if(nodes[j].color == white) dfs_visit(j);
        }
    }

    nodes[i].color = black;
    num++;
    nodes[i].label_out = num;

    topology.insert(topology.begin(),nodes[i].serial_no);
}

void dfs()          //Depth First Search - DFS
{
    int i;

    for(i = 0 ; i <n_box ; i++)
    {
        nodes[i].color = white;
        nodes[i].serial_no = i;
    }

    for(i = 0 ; i < n_box ; i++)
    {
        if(nodes[i].color == white) dfs_visit(i);
    }
}

void calculate()
{
    int i , j , len , max;

    len = topology.size();

    times.clear();
    next.clear();
    result.clear();

    for(i = 0 ; i < len ; i++)
    {
        times.push_back(1);
        next.push_back(-1);
    }

    for(i = len - 2 ; i >= 0 ; i--)
    {
        for(j = i + 1 ; j < len ; j++)
        {
            if(graph[topology[i]][topology[j]] == 1)
            {
                if((times[j] + 1) > times[i])
                {
                    times[i] = times[j] + 1;
                    next[i] = topology[j];
                }
            }
        }
    }

    max = 0;

    for(i = 0 ; i < len; i++)
    {
        if(times[i] > times[max]) max = i;
    }

    i = max;

    while(next[i] != -1)
    {
        result.insert ( result.begin() , topology[i]);

        for(int k = i+1 ; k < len ; k++)
        {
            if(topology[k] == next[i])
            {
                i = k;
                break;
            }
        }
    }

    result.insert ( result.begin() , topology[i]);

    cout << times[max] << endl;

    if(times[max] == 1) cout << '1' << endl;

    else
    {
        i = 0;

        while(i < times[max])
        {
            cout << result[i] + 1;
            i++;

            if(i < times[max]) cout << ' ';
        }
        cout << endl ;
    }
}
