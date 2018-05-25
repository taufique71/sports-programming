#include <iostream>
using namespace std;

int main()
{
    unsigned long long int start,date,result;
    unsigned long long int count,total_day,temp_start;

    while(scanf("%lld %lld",&start,&date) == 2)
    {
        count = 0;
        temp_start = start;
        total_day = start;
        for(count = 0 ; ;count++)
        {
            if(total_day >= date) break;
            else
            {
                temp_start += 1;
                total_day += temp_start;
            }
        }
        //cout << total_day << endl;
        cout << temp_start << endl;
    }

    return 0;
}
