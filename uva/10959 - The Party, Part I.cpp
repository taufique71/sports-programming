#include <iostream>
#include <queue>
#define ZERO 0
using namespace std;

const int infinity = 2147483647;

int main()
{
    int n_case;
    int p,n;
    int i,j;
    int dancer1,dancer2;
    int flag = 0;

    cin >> n_case;
    while(n_case--)
    {
        cin >> p >> n;

        int connection[ZERO+p][ZERO+p];
        int giovanni[ZERO+p];
        for(i = 0 ; i < p ; i++)
        {
            for(j = 0 ; j < p ;j++) connection[i][j] = 0;
            giovanni[i] = infinity;
        }
        giovanni[0] = 0;

        while(n--)
        {
            cin >> dancer1 >> dancer2;
            if(connection[dancer1][dancer2] || connection[dancer2][dancer1] == 0)
            {
                connection[dancer1][dancer2] = 1;
                connection[dancer2][dancer1] = 1;
            }
        }

        queue<int> q;
        q.push(0);
        while(q.size() > 0)
        {
            int index = q.front();
            q.pop();
            for(i = 1 ; i < p ; i++)
            {
                if(connection[index][i] == 1)
                {
                    if(giovanni[i] > giovanni[index]) giovanni[i] = giovanni[index] + 1;
                    for(j = 0 ; j < p ; j++) connection[j][i] = 0;
                    q.push(i);
                }
            }
        }

        if(flag == 1) cout << endl;
        for(i = 1 ; i < p ; i++) cout << giovanni[i] << endl;
        flag = 1;
    }
}
