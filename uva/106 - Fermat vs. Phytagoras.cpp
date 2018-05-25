#include <iostream>

#define N 1000000

using namespace std;

int track[N+1];

int isCoprime(int num1,int num2)
{
    int rem;

    while(num1 != 0)
    {
        rem = num2%num1;
        num2 = num1;
        num1 = rem;
    }

    if(num2 == 1) return 1;
    else return 0;
}

void init()
{
    for(int i = 0 ; i <= N ; i++) track[i] = 0;
}

int isOnlyOneEven(int num1,int num2)
{
    if((num1%2 == 1) && (num2%2 == 0)) return 1;
    else if((num1%2 == 0) && (num2%2 == 1)) return 1;
    else return 0;
}

int main()
{
    int m , n , input , count2 , count1;
    long long int a , b , c;

    while(cin >> input)
    {
        count1 = 0;
        count2 = 0;
        if(track[3] == 1) init();

        for(m = 1; m*m <= input ; m++)
        {
            for(n = 1 ; (n < m)&&((n*n + m*m) <= input) ; n++)
            {
                if(isCoprime(n,m))
                {
                    if(isOnlyOneEven(n,m))
                    {
                        a = m*m - n*n;
                        b = 2*m*n;
                        c = m*m + n*n;

                        count1++;

                        for(int i = 1; c*i <= input ; i++)
                        {
                            track[a*i] = 1;
                            track[b*i] = 1;
                            track[c*i] = 1;
                        }
                    }
                }
            }
        }

        for(int i = 1; i <= input ; i++) if(track[i] == 0) count2++;

        cout << count1 << ' ' << count2 << endl;
    }

    return 0;
}
