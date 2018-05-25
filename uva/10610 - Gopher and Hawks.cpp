#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#define MAX 1000
using namespace std;

class hole
{
public:
    double x;
    double y;
}start,end,temp;

vector<int> list[MAX+10];
vector<hole> all;
//hole all[MAX+10];
int step[MAX+10];
bool color[MAX+10];

double dist(hole a,hole b)
{
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

int main()
{
    double v,m;
    double k;
    int i,j;

    while(cin >> v >> m)
    {
        if(v == 0.00 && m == 0.00) break;

        all.clear();
        memset(step,0,sizeof(step));
        memset(color,true,sizeof(color));
        k = v*60*m;
        for(i = 0 ; i < MAX+10 ; i++) list[i].clear();

        cin >> start.x >> start.y;
        all.push_back(start);
        cin >> end.x >> end.y;
        all.push_back(end);

        string s;
        getline(cin,s);

        while(true)
        {
            getline(cin,s);
            if(s.length() == 0) break;
            stringstream ss(s);
            ss >> temp.x >> temp.y;
            all.push_back(temp);
        }

        int n = all.size();

        for(i = 0 ; i < n ; i++)
        {
            for(j = 0 ; j < i ; j++)
            {
                double d = dist(all[i],all[j]);
                if(d < k)
                {
                    list[i].push_back(j);
                    list[j].push_back(i);
                }
            }
        }

        queue<int> q;
        q.push(0);
        color[0] = false;
        bool flag = true;

        while(!q.empty())
        {
            i = q.front();
            q.pop();

            for(j = 0 ; j < list[i].size() ; j++)
            {
                if(color[list[i][j]] == true)
                {
                    q.push(list[i][j]);
                    step[list[i][j]] = step[i]+1;
                    color[list[i][j]] = false;
                    if(list[i][j] == 1)
                    {
                        flag = false;
                        break;
                    }
                }
            }
            if(flag == false) break;
        }

        if(color[1] == true) printf("No.\n");
        else printf("Yes, visiting %d other holes.\n",step[1]-1);
    }
    return 0;
}
