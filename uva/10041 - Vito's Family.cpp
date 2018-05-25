#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int kase;
    cin >> kase;

    while(kase--)
    {
        int n_rel;
        int i , min = 30000, max = 0 , j;
        int below , here , above;
        long int sum = 0 , res = 15000000;
        cin >> n_rel;
        j = n_rel;

        vector<int> street(30001 , 0);

        while(j--)
        {
            cin >> i;
            street[i]++;
            if(i < min) min = i;
            if(i > max) max = i;
        }

        below = 0;
        here = street[min];
        above = n_rel - here;

        for(i = min ; i <= max ; i++) sum += (i - min) * street[i];
        if(sum < res) res = sum;

        for(i = min + 1 ; i <= max ; i++)
        {
            below += street[i - 1];
            here = street[i];
            above -= street[i];
            sum = sum + below - (here + above);
            if(sum < res) res = sum;
        }

        cout << res << endl;
    }

    return 0;
}
