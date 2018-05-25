#include <iostream>
using namespace std;

int main()
{
    long int Z , I , M , L , count ;
    int kase = 1;

    while(cin >> Z >> I >> M >> L)
    {
        if((Z == 0)&&(I == 0)&&(M == 0)&&(L == 0)) break;

        int track[10000] = {0};

        count = 1;

        for(count = 1 ; (track[L] == 0) ; count++)
        {
            track[L] = count;
            L = ((((Z % M) * (L % M)) % M) + I) % M;
        }

        cout << "Case " << kase << ": " << count - track[L] << endl;
        kase++;
    }

    return 0;
}
