#include <iostream>
#include <cstring>

#define ZERO 0

using namespace std;

char fib[5001][1500];

void add(int j,int k)
{
    int m = strlen(fib[j]);
    int n = strlen(fib[k]);
    int a,b,c;
    int car = 0;

    char sum[ZERO + m + 2];

    sum[m + 1] = '\0';

    for(a = m -1 , b = n - 1 , c = m ; b >=0 ; a-- , b-- , c--)
    {
        sum[c] = ((fib[j][a] - 48 + fib[k][b] - 48 + car) % 10 ) + 48;
        car = ((fib[j][a] - 48 + fib[k][b] - 48 + car) / 10 );
    }

    while(a >= 0)
    {
        sum[c] = ((fib[j][a] - 48 + car) % 10 ) + 48;
        car = ((fib[j][a] - 48 + car) / 10 );

        a--;
        c--;
    }

    sum[c] = car + 48;

    if(sum[0] != '0') strcpy(fib[j+1],sum);
    else
    {
        m = 0 ;
        n = 0;

        while(sum[m] == '0') m++;

        while(sum[m] != '\0')
        {
            fib[j+1][n] = sum[m];
            m++;
            n++;
        }
        fib[j+1][n] = '\0';
    }
}

void pregenerate()
{
    strcpy(fib[0] , "0");
    strcpy(fib[1] , "1");

    for(int i = 2; i < 5001 ; i++) add(i-1,i-2);
}

int main()
{
    int n;

    pregenerate();

    while(cin >> n)
    {
        cout << "The Fibonacci number for " << n << " is ";
        cout << fib[n] << endl;
    }

    return 0;
}
