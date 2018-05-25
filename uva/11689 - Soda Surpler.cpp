#include <iostream>
using namespace std;

int main()
{
    int n_ini_can;
    int n_mid_can;
    int n_total;
    int count;
    int n_cost;
    int n_case;

    cin >> n_case;

    while(n_case--)
    {
        count = 0;
        cin >> n_ini_can >> n_mid_can >> n_cost;
        n_total = n_ini_can + n_mid_can;

        while(n_total >= n_cost)
        {
            count += n_total/n_cost;
            n_total = (n_total/n_cost) + (n_total%n_cost);
        }

        cout << count << endl;
    }

    return 0;
}
