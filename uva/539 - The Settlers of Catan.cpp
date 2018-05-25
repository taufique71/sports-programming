#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define MAX 30
using namespace std;

bool mat[MAX][MAX];
vector<int> list[MAX];
int count;
int res;

void go(int i,int c)
{
    int j;
    if(c > res) res = c;
    for(j = 0 ; j < list[i].size() ; j++)
    {
        if(mat[i][list[i][j]] == true)
        {
            mat[i][list[i][j]] = false;
            mat[list[i][j]][i] = false;
            go(list[i][j],c+1);
            mat[i][list[i][j]] = true;
            mat[list[i][j]][i] = true;
        }
    }
}

int main()
{
    int n,m;
    int i,j,a,b;

    while(cin >> n >> m)
    {
        if(n == 0 && m == 0) break;
        memset(mat,false,sizeof(mat));
        for(i = 0 ; i < MAX ; i++) list[i].clear();

        for(i = 0 ; i < m ; i++)
        {
            cin >> a >> b;
            mat[a][b] = true;
            mat[b][a] = true;
            list[a].push_back(b);
            list[b].push_back(a);
        }

        count = 0;
        res = 0;
        for(i = 0 ; i < n ; i++)
        {
            for(j = 0 ; j < list[i].size(); j++)
            {
                if(mat[i][list[i][j]] == true)
                {
                    mat[i][list[i][j]] = false;
                    mat[list[i][j]][i] = false;
                    go(list[i][j],1);
                    mat[i][list[i][j]] = true;
                    mat[list[i][j]][i] = true;
                }
            }
        }

        //cout << "result" << res << endl;
        cout << res << endl;
    }
    return 0;
}
