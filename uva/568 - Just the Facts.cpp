#include <iostream>

#define MAX 10100

using namespace std;

long long int six_digit[MAX];

long long int cut_into_six(long long int n)
{
    long long int sum = 0;
    long long int count = 0 , rem , mult = 1;

    while(n)
    {
        rem = n % 10;
        n = n / 10;

        if((rem != 0)||(count != 0))
        {
            sum += rem * mult;
            mult *= 10;
            count++;
        }

        if(count == 5) break;
    }

    return sum;
}

void generate()
{
    int i;

    six_digit[0] = 1;

    for(i = 1 ; i < MAX ; i++) six_digit[i] = cut_into_six(six_digit[i-1] * i);
}

int main()
{
    generate();

    int n;

    while(cin >> n)
    {
        printf("%5d -> ",n);
        cout << (six_digit[n] % 10) << endl;
    }

    return 0;
}
