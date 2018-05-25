#include <iostream>
#include <map>
#include <cstring>
#include <queue>
#include <string>
using namespace std;

const bool white = true;
const bool red = false;

int main()
{
    int n_case;
    int case_count = 1;
    int n_vertex,n_edge,n_request;
    int i,j,k;
    string f,s;
    int size,source,destination;
    cin >> n_case;
    printf("SHIPPING ROUTES OUTPUT\n\n");
    while(case_count <= n_case)
    {
        cin >> n_vertex >> n_edge >> n_request;

        printf("DATA SET  %d\n\n",case_count);

        bool graph[n_vertex][n_vertex];
        bool color[n_vertex];
        int cost[n_vertex];

        for(i = 0 ; i < n_vertex ; i++)
        {
            for(j = 0 ; j < n_vertex ; j++)
            {
                graph[i][j] = false;
            }
            cost[i] = 0;
            color[i] = white;
        }
        map<string,int> m;
        i = 0;
        while(i < n_vertex)
        {
            cin >> f;
            m.insert(pair<string,int>(f,i));
            i++;
        }
        k = 0;
        while(k < n_edge)
        {
            cin >> f >> s;
            i = m[f];
            j = m[s];
            graph[i][j] = graph[j][i] = true;
            k++;
        }
        while(n_request--)
        {
            cin >> size >> f >> s;

            source = m[f];
            destination = m[s];

            queue<int> q;
            q.push(source);
            cost[source] = 0;
            color[source] = red;
            bool flag = true;
            while(!q.empty() && flag)
            {
                i = q.front();
                q.pop();
                for(j = 0 ; j < n_vertex && flag ; j++)
                {
                    if(graph[i][j] && color[j] == white)
                    {
                        if(j == destination) flag = false;
                        q.push(j);
                        cost[j] = cost[i]+1;
                        color[j] = red;
                    }
                }
            }

            if(color[destination] == white) printf("NO SHIPMENT POSSIBLE\n");
            else printf("$%d\n",size*cost[destination]*100);

            for(i = 0 ; i < n_vertex ; i++)
            {
                cost[i] = 0;
                color[i] = white;
            }
        }
        cout << endl;
        case_count++;
    }

    cout << "END OF OUTPUT" << endl;

    return 0;
}
