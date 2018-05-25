#include <iostream>

#define MAX 1000001

using namespace std;

int prime[MAX];

void sieve_eratosthenes()
{
    int i,j;

    prime[0] = 1;
    prime[1] = 1;

    for(i = 2 ; i < MAX ;)
    {
        if(i*i > MAX) break;
        for(j = i+i ; j < MAX ; j += i) prime[j] = 1;
        for(i++ ; (i < MAX)&&(prime[i] != 0) ; i++);
    }
    return;
}

int main()
{
    sieve_eratosthenes();
    int n;
    int flag;

    while(cin >> n)
    {
        if(n == 0) break;
        cout << n << ':' << endl;
        flag = 0;
        for(int i = 2, j = n - i ; i <= j ; i++,j-- )
        {
            if((prime[i] == 0) && (prime[j] == 0))
            {
                flag = 1;
                cout << i << '+' << j << endl;
                break;
            }
        }
        if(flag == 0) cout << "NO WAY!" << endl;
    }
    return 0;
}
