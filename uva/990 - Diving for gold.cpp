#include <iostream>
#include <cstdio>
#define MAX_TREASURE 35
#define MAX_TIME 1010
using namespace std;

class treasure
{
public:
    int depth;
    int value;
};

int depth_factor;
int total_time,n_treasure;
int depth[MAX_TREASURE];
int cost[MAX_TREASURE];
int value[MAX_TREASURE];
bool table[MAX_TREASURE][MAX_TIME];

int Knapsack()
{
    int knapsack_arr[MAX_TIME] = {0};
    int i,j;

    for(i = n_treasure-1 ; i >= 0 ; i--)
    {
        for(j = total_time ; j >= cost[i] ; j--)
        {
            int a = knapsack_arr[j];
            int b = knapsack_arr[j-cost[i]] + value[i];

            if(b > a)
            {
                knapsack_arr[j] = b;
                table[i][j] = true;
            }
            else table[i][j] = false;
        }
    }

    return knapsack_arr[total_time];
}

int main()
{
    int i,j;
    int n;
    bool flag = false;
    while(scanf("%d %d",&total_time,&depth_factor) == 2)
    {
        scanf("%d",&n_treasure);
        i = 0;
        while(i < n_treasure)
        {
            scanf("%d %d",&depth[i],&value[i]);
            cost[i] = depth_factor*depth[i] + 2*depth_factor*depth[i];
            i++;
        }
        n = Knapsack();

        treasure results[MAX_TREASURE];
        int in = 0;

        for(i = 0 , j = total_time ; i < n_treasure ; i++)
        {
            if(table[i][j] == true)
            {
                results[in].depth = depth[i];
                results[in].value = value[i];
                in++;
                j = j-cost[i];
            }
        }

        if(flag) cout << endl;
        cout << n << endl << in << endl;
        for(i = 0 ; i < in ; i++)
        {
            cout << results[i].depth << ' ' << results[i].value << endl;
        }
        flag = true;
    }
    return 0;
}
