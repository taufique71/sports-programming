#include <iostream>
#include <cstdio>
#define MAX_OBJ 1010
#define MAX_CAP 35
using namespace std;

int n_object;
int weight[MAX_OBJ];
int value[MAX_OBJ];

int max(int a,int b)
{
    if(a >= b) return a;
    else return b;
}

int knapsack(int capacity)
{
    int i,j;
    int arr[MAX_CAP] = {0};
    for(i = 0 ; i < n_object ; i++)
    {
        for(j = capacity ; j >= weight[i] ; j--)
        {
            arr[j] = max(arr[j],arr[j-weight[i]]+value[i]);
        }
    }

    return arr[capacity];
}

int main()
{
    int n_case,n_member;
    int i,j;
    int result;
    int capacity;
    scanf("%d",&n_case);

    while(n_case--)
    {
        scanf("%d",&n_object);
        for(i = 0 ; i < n_object ; i++)
        {
            scanf("%d %d",&value[i],&weight[i]);
        }

        result = 0;
        scanf("%d",&n_member);
        while(n_member--)
        {
            scanf("%d",&capacity);
            result += knapsack(capacity);
        }
        printf("%d\n",result);
    }

    return 0;
}
