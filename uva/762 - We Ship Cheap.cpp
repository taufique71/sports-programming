#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <queue>
#include <stack>
#define MAX 1000
using namespace std;

int graph[MAX][MAX];

int main()
{
    int n_lines;
    int i,j,k,a,b;
    string start = new char[10];
    string end = new char[10];
    int pred[MAX];
    int color[MAX];
    bool flag = false;

    while(cin >> n_lines)
    {
        if(flag) cout << endl;
        map<string,int> m;
        for(i = 0 ; i < MAX ; i++)
        {
            pred[i] = -1;
            color[i] = 1;
        }
        string nodes[MAX];
        k = 0;

        memset(graph,0,sizeof(graph));

        for(i = 0 ; i < n_lines ; i++)
        {
            cin >> start >> end;
            if(m.find(start) == m.end())
            {
                m.insert(pair<string,int>(start,k));
                nodes[k] = start;
                k++;
            }
            if(m.find(end) == m.end())
            {
                m.insert(pair<string,int>(end,k));
                nodes[k] = end;
                k++;
            }
            a = m[start];
            b = m[end];

            graph[a][b] = 1;
            graph[b][a] = 1;
        }

        cin >> start >> end;
        if(m.find(start) == m.end() || m.find(end) == m.end())
        {
            cout << "No route" << endl;
        }
        else
        {
            a = m[start];
            b = m[end];
            queue<int> q;
            q.push(a);
            color[a] = 0;

            while(!q.empty())
            {
                i = q.front();
                q.pop();

                for(j = 0 ; j < k ; j++)
                {
                    if(graph[i][j] == 1 && color[j] == 1)
                    {
                        q.push(j);
                        color[j] = 0;
                        pred[j] = i;
                    }
                }
            }

            if(color[b] == 1)
            {
                cout << "No route" << endl;
            }
            else
            {
                stack<int> s;

                for(i = b; pred[i] >= 0 ; )
                {
                    s.push(i);
                    i = pred[i];
                }

                if(s.size() > 0)
                {
                    j = s.top();
                    s.pop();
                }

                while(!s.empty())
                {
                    cout << nodes[i] << ' ' << nodes[j] << endl;
                    i = j;
                    j = s.top();
                    s.pop();
                }
                cout << nodes[i] << ' ' << nodes[j] << endl;
            }
        }

        flag = true;
    }
    return 0;
}
