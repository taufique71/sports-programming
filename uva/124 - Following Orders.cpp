#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 30
using namespace std;

bool graph[MAX][MAX];
bool color[150];
char res[MAX];
int n_res;
char nodes[MAX];
int n_nodes;

void backtrack(int n)
{
    if(n >= n_nodes)
    {
        res[n_res] = '\0';
        for(int i =0 ; i < n_res ; i++) cout << res[i];
        cout << endl;
        return;
    }

    int i,j;
    bool flag;

    for(i = 0 ; i < n_nodes ; i++)
    {
        if(color[nodes[i]] == true)
        {
            flag = true;
            for(j = 0 ; j < MAX ; j++)
            {
                if(graph[j][nodes[i]-'a'] == true && color[j+'a'] == true)
                {
                    flag = false;
                    break;
                }
            }
            if(flag == true)
            {
                res[n_res] = nodes[i];
                n_res++;
                color[nodes[i]] = false;
                backtrack(n+1);
                color[nodes[i]] = true;
                n_res--;
            }
        }
    }
}

int main()
{
    int i,j;
    char input[100];
    char order[500];
    bool flag = false;

    while(gets(input))
    {
        gets(order);
        memset(color,false,sizeof(color));
        memset(graph,false,sizeof(graph));
        n_nodes = 0;
        for(i = 0 ; input[i] ; i++)
        {
            if(input[i]!=' ')
            {
                nodes[n_nodes] = input[i];
                color[input[i]] = true;
                n_nodes++;
            }
        }
        sort(nodes,nodes+n_nodes);

        int len = strlen(order);
        for(j = 0; (j < len)&&(j+2 < len) ; j+=4)
        {
            if((order[j]-'a' >= 0) && (order[j+2]-'a' >= 0)) graph[order[j]-'a'][order[j+2]-'a'] = true;
        }
        if(flag) cout << endl;
        backtrack(0);
        flag = true;
    }
    return 0;
}
