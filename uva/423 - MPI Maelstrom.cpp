#include <iostream>
#include <queue>
#include <cstdlib>
using namespace std;

const int red = 1;
const int white = 0;
const int infinity = 2147483647;

class processor
{
public:
    int color;
    int weight;
    int n;

    const bool operator<(const processor &a) const
    {
        if(this->weight < a.weight) return true;
        else return false;
    }
    const bool operator>(const processor &a) const
    {
        if(this->weight > a.weight) return true;
        else return false;
    }
};

int main()
{
    int n;
    int i,j;
    int result;
    char input[100];
    processor temp;
    priority_queue< processor,vector<processor>,greater<processor> > q;

    cin >> n;

    int map[n][n];
    processor nodes[n];

    for(i = 0 ; i < n ; i++)
    {
        for(j = 0 ; j < i ; j++)
        {
            map[i][j] = infinity;
            map[j][i] = infinity;
            cin >> input;
            if(strcmp(input,"x") != 0)
            {
                map[i][j] = atoi(input);
                map[j][i] = map[i][j];
            }
        }
        map[i][j] = 0;

        nodes[i].color = white;
        nodes[i].weight = infinity;
        nodes[i].n = i;
    }

    nodes[0].weight = 0;
    result = nodes[0].weight;
    q.push(nodes[0]);
    while(!q.empty())
    {
        temp = q.top();
        q.pop();
        if(nodes[temp.n].color != red)
        {
            nodes[temp.n].color = red;
            if(nodes[temp.n].weight > result) result = nodes[temp.n].weight;
            for(i = 0 ; i < n ; i++)
            {
                if(map[temp.n][i] != infinity)
                {
                    if(nodes[temp.n].weight+map[temp.n][i] < nodes[i].weight)
                    {
                        nodes[i].weight = nodes[temp.n].weight+map[temp.n][i];
                        q.push(nodes[i]);
                    }
                }
            }
        }
    }
    cout << result << endl;

    return 0;
}
