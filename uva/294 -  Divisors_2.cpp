#include <iostream>
#include <cmath>
using namespace std;

long int cnt,result;

void calc(long int u,long int l)
{
    cnt = 0;
    result = 0;
    long int max = 0;

    int i,j;

    for(i = l;i <= u;i++)
    {
        max = 0;

        long int limit = floor(sqrt(i));

        for(j = 1;j <= limit; j++)
        {
            if(!(i % j)) max = max + 2;
        }

        if(floor(sqrt(i)) == ceil(sqrt(i))) max = max - 1;

        if(max >= cnt)
        {
            if(max == cnt)
            {
                if(result > i) result = i;
            }

            else
            {
                cnt = max;
                result = i;
            }
        }
    }

}

int main()
{
    long int cases;
    long int u , l;

    cin >> cases;

    while(cases --)
    {
        cin >> l >> u;
        calc(u,l);
        cout << "Between " << l << " and " << u << ", " << result << " has a maximum of " << cnt << " divisors."<<endl;
    }

    return 0;
}
