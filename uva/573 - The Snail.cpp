#include <iostream>
using namespace std;

int main()
{
    double total_height;
    int count_day;
    double up_dis;
    double down_dis;
    double fatigue_factor;
    double travelled;

    while(scanf("%lf %lf %lf %lf",&total_height,&up_dis,&down_dis,&fatigue_factor) == 4)
    {
        if(total_height == 0) break;

        count_day = 1;
        travelled = 0;
        fatigue_factor = up_dis * fatigue_factor / 100;

        while(1)
        {
            if((up_dis - fatigue_factor * (count_day-1)) > 0) travelled += up_dis - fatigue_factor * (count_day-1);
            if(travelled > total_height) break;
            travelled -= down_dis;
            if(travelled < 0) break;
            count_day++;
        }

        if(travelled < 0) printf("failure on day %d\n",count_day);
        else printf("success on day %d\n",count_day);
    }

    return 0;
}
