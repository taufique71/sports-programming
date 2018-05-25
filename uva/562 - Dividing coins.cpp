#include <iostream>
#include <cstdio>
#define N 50010
using namespace std;

int coins[110];
int sum;
int n_coins;

int max(int a,int b)
{
    if(a >= b) return a;
    else return b;
}

int DP()
{
    int c = sum/2;
    int arr[N]={0};
    int i,j,k;
    for(i = 0 ; i < n_coins ; i++)
    {
        for(j = c; j >= coins[i] ; j--)
        {
            arr[j] = max(arr[j],arr[j-coins[i]]+coins[i]);
            //cout << arr[j] << ' ';
        }
        //cout << endl;
    }

    return arr[c];
}

int main()
{
    int i,j,n_cases;
    scanf("%d",&n_cases);

    while(n_cases--)
    {
        cin >> n_coins;
        i = 0;
        sum = 0;
        while(i < n_coins)
        {
            scanf("%d",&coins[i]);
            sum += coins[i];
            i++;
        }
        int person_1 = DP();
        printf("%d\n",sum-person_1-person_1);
    }

}
