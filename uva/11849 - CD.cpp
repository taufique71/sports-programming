#include <iostream>
#include <algorithm>
#define ZERO 0
using namespace std;

int main()
{
    int jack,jill;
    int i;
    int count;

    while(scanf("%d %d",&jack,&jill))
    {
        if(jack == 0 && jill == 0) break;

        int Jack[ZERO+jack];

        int cd_no;

        for(i = 0 ; i < jack ; i++) scanf("%d",&Jack[i]);
        sort(Jack,Jack+jack);

        count = 0;

        for(i = 0 ; i < jill ; i++)
        {
            cin >> cd_no;

            if(binary_search(Jack,Jack+jack,cd_no)) count++;
        }

        printf("%d\n",count);
    }

    return 0;
}
