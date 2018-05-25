#include <iostream>
#include <queue>
#include <cstring>

#define MAX 1000
#define MAX_NODE 30

using namespace std;

int white = 0;
int red = 1;

char input[MAX][3];
int graph[MAX_NODE][MAX_NODE];
int nodes[MAX_NODE];

void re_init()
{
    for(int i = 0 ; i < MAX ; i++) strcpy(input[i] , "");
    for(int i = 0 ; i < MAX_NODE ; i++)
    {
        for(int j = 0 ; j < MAX_NODE ; j++) graph[i][j] = 0;
        nodes[i] = white;
    }
}

void flood_fill(int i , int tar , int dsrd)
{
    queue<int> q;
    int index;

    if(nodes[i] != tar) return;

    nodes[i] = red;
    q.push(i);

    while(!q.empty())
    {
        index = q.front();
        q.pop();

        for(i = 0 ; i < MAX_NODE ; i++)
        {
            if((graph[index][i] == 1) && (nodes[i] == white))
            {
                nodes[i] = red;
                q.push(i);
            }
        }
    }

    return ;
}

int main()
{
    int kase;
    char gar[5];
    char c;

    cin >> kase;
    //gets(gar);

    while(kase--)
    {
        cin >> c;
        gets(gar);
        int i = 0 , j , k , count;
        re_init();
        while(gets(input[i]))
        {
            if(!strcmp(input[i] , "")) break;
            i++;
        }

        for(j = 0 ; j < i ; j++)
        {
            graph[input[j][0]-65][input[j][1]-65] = 1;
            graph[input[j][1]-65][input[j][0]-65] = 1;
        }

        count = 0;

        for(i = 0 ; i <= (c-65) ; i++)
        {
            if(nodes[i] == white)
            {
                flood_fill(i , white , red);
                count++;
            }
        }
        cout << count << endl;
        if(kase) cout << endl;
    }

    return 0;
}
