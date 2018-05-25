#include <iostream>
#define ZERO 0
using namespace std;

int main()
{
    int n_case = 1;
    int max_case;
    int n,num;
    int i;
    cin >> max_case;

    while(n_case <= max_case)
    {
        cin >> n;
        int list[ZERO + n];
        i = 0;

        while(i < n) cin >> list[i++];
        cout << "Case " << n_case << ": ";
        if(n%2) cout << list[n/2] << endl;
        else
        {
            if(list[0] < list[n-1]) cout << list[n/2] <<endl;
            else cout << list[n/2-1] << endl;
        }
        n_case++;
    }

    return 0;
}
