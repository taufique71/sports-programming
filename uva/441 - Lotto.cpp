#include <iostream>
#include <vector>
using namespace std;

vector<int> result;
int input[50];
int k;

void backtrack(int i)
{
    if(result.size() == 6)
    {
        for(int j = 0 ; j < 6 ; j++)
        {
            cout << result[j];
            if(j+1 < 6) cout << ' ';
        }
        cout << endl;
        return;
    }

    for(i ; i < k ; i++)
    {
        result.push_back(input[i]);
        backtrack(i+1);
        result.pop_back();
    }
}

int main()
{
    int i,n_case = 0;

    while(cin >> k)
    {
        if(k == 0) break;
        result.clear();
        for(i = 0 ; i < k ; i++) cin >> input[i];
        if(n_case) cout << endl;
        backtrack(0);
        n_case++;
    }

    return 0;
}
