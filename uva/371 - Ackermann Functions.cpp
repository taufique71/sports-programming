#include <iostream>
#define MAX 3000000

using namespace std;

long long int track[MAX];

struct
{
    long long int number;
    long long int sequence;
}result;

long long int calculate(long long int n)
{
    long long int count = 0;

    if(n == 1) return 0;

    if((n < MAX)&&(track[n])) return track[n];

    else
    {
        if(n % 2) count = calculate((3*n)+1) + 1;
        else count = calculate(n/2) + 1;
    }

    if(n < MAX) track[n] = count;

    return count;
}

int main()
{
    long long int a , b ;
    long long int start , end ;

    track[1] = 3;
    track[0] = 0;

    while(cin >> a >> b)
    {
        if((a == 0)&&(b == 0)) break;

        if(a >= b) {start = b; end = a;}
        else {start = a; end = b;}

        result.number = 0;
        result.sequence = 0;

        for(long long int i = start ; i <= end ; i++)
        {
            long long int ans;

            if(i == 0 || i == 1) ans = track[i];
            else ans = calculate(i);

            if(ans > result.sequence)
            {
                result.number = i;
                result.sequence = ans;
            }
        }

        printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n",start , end , result.number , result.sequence);
    }

    return 0;
}
