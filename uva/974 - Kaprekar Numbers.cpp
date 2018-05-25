#include <iostream>
#define MAX 40001
using namespace std;

int kaprekar[MAX];

void pre_calc()
{
    int first,second,square,multiplier;
    int i;

    for(i = 2 ; i < MAX ; i++)
    {
        second = 0;
        square = i*i;
        for(first = square,multiplier = 1 ; first > 0 ; multiplier *= 10)
        {
            second = (first%10)*multiplier + second;
            first = first/10;
            if(first>0 && second>0)
            {
                if(first+second == i)
                {
                    kaprekar[i] = 1;
                    break;
                }
            }
        }
    }
}

int main()
{
    pre_calc();

    int n_case;
    int case_count = 1;
    int count;
    int lower,upper;
    int i;

    scanf("%d",&n_case);

    while(case_count <= n_case)
    {
        scanf("%d %d",&lower,&upper);

        if(case_count > 1) printf("\n");
        printf("case #%d\n",case_count);

        count = 0;

        for(i = lower ; i <= upper ; i++)
        {
            if(kaprekar[i])
            {
                printf("%d\n",i);
                count++;
            }
        }

        if(count == 0) printf("no kaprekar numbers\n");

        case_count++;
    }

    return 0;
}
