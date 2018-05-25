/**************************************************************************************************

#include <iostream>

#define MAX 70000000

using namespace std;

long long int sum[MAX];

void init_sum()
{
    long long int s = 0;
    long long int i;

    for(i = 0 ; i < MAX ; i++)
    {
        s += i;
        sum[i] = s;
    }
}

int main()
{
    long long int i , j , j_track = 0 , sum_below , sum_above , res_1 , res_2;
    int count = 0;

    init_sum();

    for(i = 1 ; i < MAX ; i++)
    {
        sum_below = sum[i - 1];
        sum_above = sum[i + 1] - sum[i];
        for(j = i + 1 ; sum_above < sum_below ; j++)
        {
            sum_above = sum[j] - sum[i];
        }

        if(sum_above == sum_below)
        {
            count++;
            printf("%10lld%10lld\n", i , j - 1);
        }
        if(count >= 10) break;
    }

    return 0;
}

******************************** নাম্বার গুলা বের করার জন্য উপরের প্রগ্রাম। এখান থেকে ধৈর্য ধরে নাম্বার গুলা জেনারেট করার পর সেগুলা ব্যবহার করে খালি আউটপুট হবে নিচের প্রগ্রামে **********************/



#include <iostream>

#define MAX 10

using namespace std;

long long int house[] = {6,35,204,1189,6930,40391,235416,1372105,7997214,46611179};
long long int lasth[] = {8,49,288,1681,9800,57121,332928,1940449,11309768,65918161};

int main()
{
    int i;
    for(i = 0 ; i < MAX ; i++) printf("%10lld%10lld\n",house[i],lasth[i]);
    return 0;
}
