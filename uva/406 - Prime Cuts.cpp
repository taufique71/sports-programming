#include <iostream>
#include <vector>
using namespace std;

vector<int> prime;

void seive()
{
    int p[1001];
    for(int i = 0 ; i < 1001 ; i++) p[i] = 1;

    p[0] = 0;
    for(int i = 2; i*i < 1001 ; )
    {
        p[i] = 1;

        for(int j = i + i ; j < 1001 ; j = j + i) p[j] = 0;

        for(i++ ; (i <= 1001) && (!p[i]) ; i++);
    }

    for(int i = 0 ; i < 1001 ; i++)
    {
        if(p[i] != 0) prime.push_back(i);
    }
}

int main()
{
    int N,C;

    seive();

    while(cin >> N >> C)
    {
        vector<int> list;

        int i = 0;
        while((prime[i] <= N) && (i < prime.size()))
        {
            list.push_back(prime[i]);
            i++;
        }

        if(N == C)
        {
            cout << N << ' ' << C << ':';
            for(int i = 0 ; i < list.size() ; i++) cout << ' ' << list[i];
            cout << endl << endl;
        }

        else if(list.size() % 2 == 0)
        {
            int mid = list.size() / 2 - 1;
            mid = mid - C + 1;

            if(mid >= 0)
            {
                cout << N << ' ' << C << ':';
                for(int i = 0 ; i < 2 * C ; i++) cout << ' ' << list[mid + i];
                cout << endl << endl;
            }

            else
            {
                cout << N << ' ' << C << ':';
                for(int i = 0 ; i < list.size() ; i++) cout << ' ' << list[i];
                cout << endl << endl;
            }
        }

        else
        {
            int mid = list.size() / 2 ;
            mid = mid - (C - 1);

            if(mid >= 0)
            {
                cout << N << ' ' << C << ':';
                for(int i = 0 ; i < ((2 * C) - 1) ; i++) cout << ' ' << list[mid + i];
                cout << endl << endl;
            }

            else
            {
                cout << N << ' ' << C << ':';
                for(int i = 0 ; i < list.size() ; i++) cout << ' ' << list[i];
                cout << endl << endl;
            }
        }

    }

    return 0;
}
