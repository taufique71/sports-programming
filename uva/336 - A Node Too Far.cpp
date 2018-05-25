#include <iostream>
#include <map>
#include <queue>
using namespace std;

const int white = true;
const int red = false;

bool network[40][40];

int main()
{
    int i,j;
    int n_case = 0;
    int n_connection;
    int t,a,b,k;

    while(cin >> n_connection)
    {
        if(n_connection == 0) break;
        for(i = 0 ; i < 40 ; i++)
        {
            for(j = 0 ; j < 40 ; j++) network[i][j] = false;
        }
        map<int,int> m;
        t = 0;
        for(j = 0 ; j < n_connection ; j++)
        {
            cin >> a >> b;
            if(m.find(a) == m.end()) m[a] = t++;
            if(m.find(b) == m.end()) m[b] = t++;

            network[m[a]][m[b]] = true;
            network[m[b]][m[a]] = true;
        }

        while(cin >> a >> b)
        {
            if(a == 0 && b == 0) break;
            n_case++;

            queue<int> q;
            bool pc[t];
            int ttl[t];
            for(i = 0 ; i < t ; i++)
            {
                pc[i] = white;
                ttl[i] = 0;
            }

            i = m[a];
            q.push(i);
            pc[i] = red;
            ttl[i] = 0;

            while(!q.empty())
            {
                i = q.front();
                q.pop();
                if(ttl[i] >= b) break;
                for(j = 0 ; j < t; j++)
                {
                    if(network[i][j] == true && pc[j] == white)
                    {
                        q.push(j);
                        pc[j] = red;
                        ttl[j] = ttl[i]+1;
                    }
                }
            }

            int result = 0;
            for(i = 0 ; i < t ; i++) if(pc[i] == white) result++;
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",n_case,result,a,b);
        }
    }
    return 0;
}
