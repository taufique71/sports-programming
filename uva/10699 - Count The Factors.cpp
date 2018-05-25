#include <iostream>
#include <vector>

#define MAX 1000001

using namespace std;

int p[1000001];
vector<int> prime;

void seive()
{
    int i , j ;

    for(i = 0 ; i < MAX ; i++) p[i] = 1;

    p[0] = 0 ;
    p[1] = 0 ;

    for(i = 2 ; (i*i) < MAX ; )
    {
        for(j = i+i ; j < MAX ; j = j+i) p[j] = 0;
        for(i++ ;((i < MAX) && (!p[i])); i++);
    }

    for(i = 0 ; i < MAX ; i++)
    {
        if(p[i]) prime.push_back(i);
    }
}

int main()
{
    int i;
    int count;
    int input;
    seive();
    int l = prime.size();

    while(cin >> input)
    {
        if(input == 0) break;
        count = 0;

        for(i = 0 ; (i < input)&&(i < l) ; i++)
        {
            if(input % prime[i] == 0) count++;
        }

        cout << input << " : " << count << endl;
    }

    return 0;
}

