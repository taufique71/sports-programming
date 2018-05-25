#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX_SIZE 30
#define MAX_LINE 10000
using namespace std;

class node
{
public:
    char c;
    int f;
    int l;
};

char indx[MAX_LINE][MAX_SIZE];
bool graph[MAX_SIZE][MAX_SIZE];
bool color[MAX_SIZE];
node n[MAX_SIZE];
int t;

bool compare(node a,node b)
{
    if(a.l > b.l) return true;
    else return false;
}

void dfs(int i)
{
    color[i] = false;
    n[i].f = t++;
    for(int j = 0 ; j < MAX_SIZE ; j++)
    {
        if(graph[i][j] == true && color[j] == true)
        {
            dfs(j);
        }
    }
    n[i].l = t++;
}

int main()
{
    int i,j,k;
    bool flag = false;
    char a,b;

    t = 0;

    for(i = 0 ; i < MAX_SIZE ; i++)
    {
        n[i].c = i+'A';
        n[i].f = -1;
        n[i].l = -1;
    }

    i = 0;
    while(cin >> indx[i])
    {
        if(strcmp(indx[i],"#") == 0) break;
        i++;
    }

    j =i-1;
    for(i = 0 ; i < j ; i++)
    {
        flag = false;
        for(k = 0 ; indx[i][k] && indx[i+1][k] ; k++)
        {
            if(indx[i][k] != indx[i+1][k])
            {
                flag = true;
                break;
            }
        }
        if(flag == true)
        {
            a = indx[i][k];
            b = indx[i+1][k];
            graph[a-'A'][b-'A'] = true;
            color[a-'A'] = true;
            color[b-'A'] = true;
        }
    }

    for(i = 0 ; i < MAX_SIZE ; i++)
    {
        if(color[i] == true) dfs(i);
    }

    sort(n,n+MAX_SIZE,compare);

    for(i = 0 ; i < MAX_SIZE ; i++)
    {
        if(n[i].l >= 0) cout << n[i].c;
    }
    cout << endl;

    return 0;
}
