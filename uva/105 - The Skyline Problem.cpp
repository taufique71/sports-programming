#include <iostream>

#define SIZE 10001

using namespace std;

int cord[SIZE];

int main()
{
    int fx,lx,h;
    int i,trackh;

    while(cin >> fx >> h >> lx)
    {
        for(i = fx; i < lx ; i++)
        {
            if(cord[i] < h) cord[i] = h;
        }
    }

    for(i = 0 ; ;i++) if(cord[i] != 0) break;
    cout << i << ' ' << cord[i];
    trackh = cord[i];

    for(; i < SIZE ;i++)
    {
        if(cord[i] != trackh)
        {
            cout << ' ' << i << ' ' << cord[i];
            trackh = cord[i];
        }
    }

    cout << endl;

    return 0;
}
