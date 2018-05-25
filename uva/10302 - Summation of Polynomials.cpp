#include <iostream>

#define MAX 50001

using namespace std;

long long int arr[MAX];

void init()
{
    long long int i;

    for(i = 1 ; i < MAX ; i++)
    {
        arr[i] = arr[i - 1] + (i * i * i);
    }
}

int main()
{
    init();
    long int n;

    while(cin >> n) cout << arr[n] << endl;

    return 0;
}
