#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(int a,int b)
{
    if(a >= b) return true;
    else return false;
}

int main()
{
    int n_case;
    int n_items;
    int price;

    cin >> n_case;

    while(n_case--)
    {
        cin >> n_items;
        vector<int> prices;
        while(n_items--)
        {
            cin >> price;
            prices.push_back(price);
        }
        sort(prices.begin(),prices.end(),compare);

        int n_price = prices.size();
        int i;
        int sum = 0;

        for(i = 2 ; i < n_price ; i+=3) sum += prices[i];
        cout << sum << endl;
    }

    return 0;
}
