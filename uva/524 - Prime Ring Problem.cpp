#include <iostream>
#include <vector>
using namespace std;

int n;
int prime[50];
vector<int> result;
int track[20];

void sieve()
{
    int i,j;
    for(i = 0 ; i < 50 ; i++) prime[i] = 1;

    for(i = 2 ; i < 50 ;)
    {
        if(i*i > 50) break;
        for(j = i+i; j < 50 ; j += i) prime[j] = 0;
        for(i++; prime[i]!=1 && i < 50 ; i++);
    }
}

void backtrack()
{
    if(result.size() == n)
    {
        if(prime[result[result.size()-1]+result[0]] && prime[result[result.size()-1]+result[result.size()-2]])
        for(int i = 0; i < result.size() ; i++)
        {
            if(i < (result.size()-1)) cout << result[i] << ' ';
            else cout << result[i] << endl;
        }
        return;
    }

    if(result.size() >= 2) if(prime[result[result.size()-1]+result[result.size()-2]] != 1) return;

    for(int i = 2 ; i <= n ; i++)
    {
        if(track[i] != 0)
        {
            result.push_back(i);
            track[i] = 0;
            backtrack();
            track[i] = 1;
            result.pop_back();
        }
    }
}

int main()
{
    int i,j;
    sieve();
    int n_case = 1;

    while(cin >> n)
    {
        result.clear();
        result.push_back(1);
        if(n_case > 1) cout << endl;
        for(i = 0 ; i < 50 ; i++) track[i] = 1;
        printf("Case %d:\n",n_case);
        backtrack();
        n_case++;
    }
    return 0;
}
