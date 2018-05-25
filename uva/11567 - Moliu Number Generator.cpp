#include <iostream>
#include <cmath>
using namespace std;

long long int choice(long long int s)
{
    long long int s1 = s + 1;
    long long int s2 = s - 1;

    int j = 0;

    if(s == 3) return 2;
    if(s2 == 0) return 0;

    while(s1%2 == 0 && s1 != 0)
    {
        s1 = s1 / 2;
        j++;
    }

    while(s2%2 == 0 && s2 != 0)
    {
        s2 = s2 / 2;
        j--;
    }

    if(j > 0) return (s+1);
    else return (s-1);
}

int main()
{
    long long int n,s,count;
    while(cin >> s)
    {
        count = 0;
        while(s != 0)
        {
            if(s % 2 == 0) s = s/2;
            else s = choice(s);
            count++;
        }
        cout << count << endl;
    }

    return 0;
}
