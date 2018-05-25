#include <iostream>
#define ZERO 0
using namespace std;

struct Person
{
    int roll_no;
    bool is_alive;
};

int main()
{
    int n,k;
    int i,j;
    int count;
    int res;
    int flag = 0;
    int bury_index;

    while(cin >> n >> k)
    {
        if(n == 0 && k == 0) break;
        if(n == 1) cout << 1 << endl;
        else
        {
            Person map[ZERO + n];

            for(i = 0 ; i < n ; i++)
            {
                map[i].roll_no = i+1;
                map[i].is_alive = true;
            }

            flag = 0;

            for(i = 0 ; i < n-1 ; i++)
            {
                if(flag == 0)
                {
                    bury_index = k%n;
                    if(bury_index-1 >= 0) bury_index -= 1;
                    else bury_index = n-1;

                    map[bury_index].is_alive = false;
                }
                else
                {
                    count = 0;
                    for(j = (bury_index + 1)%n ; count < k ;)
                    {
                        if(map[j].is_alive == true) count++;
                        j = (j+1) % n;
                    }
                    if(j-1 >= 0) j = j-1;
                    else j = n-1;

                    bury_index = j;
                    map[j].is_alive = false;
                }

                count = 0;
                for(j = (bury_index + 1)%n ; count < k ;)
                {
                    if(map[j].is_alive == true) count++;
                    j = (j+1) % n;
                }
                if(j-1 >= 0) j = j-1;
                else j = n-1;

                map[bury_index] = map[j];
                map[j].is_alive = false;

                flag = 1;
            }

            res = 1 + (n - map[bury_index].roll_no + 1);
            if(res > n) res %= n;
            cout << res << endl;
        }
    }
    return 0;
}
