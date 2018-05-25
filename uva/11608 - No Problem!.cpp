#include <iostream>
using namespace std;

int main()
{
    int ready;
    int i;
    int kase = 1;

    while(scanf("%d",&ready))
    {
        if(ready < 0) break;
        int production[12];
        int required[12];
        for(i = 0 ; i < 12 ; i++) scanf("%d",&production[i]);
        for(i = 0 ; i < 12 ; i++) scanf("%d",&required[i]);

        printf("Case %d:\n",kase);
        for(i = 0 ; i < 12 ; i++)
        {
            if(ready >= required[i])
            {
                printf("No problem! :D\n");
                ready += production[i] - required[i];
            }
            else
            {
                printf("No problem. :(\n");
                ready += production[i];
            }
        }
        kase++;
    }

    return 0;
}
