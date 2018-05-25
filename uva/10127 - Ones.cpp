#include <iostream>
using namespace std;

int main()
{
    int N;
    while(cin >> N)
    {
        int one = 1;
        int rem = 1;
        while(rem)
        {
            if(N > rem)
            {
                rem = rem * 10 + 1;
                one++;
            }

            rem = rem % N;
        }
        cout << one << endl;
    }
    return 0;
}
