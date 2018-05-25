#include <iostream>

#define MAX 1000100
#define RANGE 1000001

using namespace std;

int numbers[MAX];

int calculate(int n)
{
    int ans = n;
    char str[10];

    sprintf(str , "%d" , n);

    for(int i = 0 ; str[i] ; i++)
    {
        ans += str[i] - '0';
    }

    return ans;
}

int main()
{
    int i = 1;

    numbers[0] = 1;
    for(i = 1 ; i < RANGE ; i++)
    {
        numbers[calculate(i)] = 1;
    }

    for(i = 0 ; i < RANGE ; i++)
    {
        if(numbers[i] == 0) cout << i << endl;
    }

    return 0;
}
