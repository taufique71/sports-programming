#include <iostream>
#include <cmath>

#define ZERO 0

using namespace std;

int GCD(int m , int n)
{
    int big;
    int small;
    int rem = 1;

    if(m >= n)
    {
        big = m;
        small = n;
    }
    else
    {
        big = n;
        small = m;
    }

    while(small != 0)
    {
        rem = small;
        small = big % small;
        big = rem;
    }

    return rem;
}

int main()
{
    int n , n_num;
    int i , j ;
    double pi , count_c , count_nc;

    while(cin >> n)
    {
        if(n == 0) break;

        n_num = n;
        int numbers[ZERO + n];
        i = 0;
        while(n_num --)
        {
            cin >> numbers[i];
            i++;
        }

        count_c = 0;
        count_nc = 0;

        for(i = 0 ; i < n ; i++)
        {
            for(j = i + 1 ; j < n ; j++)
            {
                if(GCD(numbers[i],numbers[j]) == 1) count_c += 1;
                count_nc += 1;
            }
        }

        if(count_c == 0 || count_nc == 0)
        {
            cout << "No estimate for this data set." << endl;
        }

        else
        {
            pi = sqrt((6*count_nc) / count_c);
            printf("%0.6lf\n" , pi);
        }
    }

    return 0;
}
