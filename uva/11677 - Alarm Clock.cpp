#include <iostream>
using namespace std;

int main()
{
    int H1,M1,H2,M2;
    int minutes;

    while(cin >> H1 >> M1 >> H2 >> M2)
    {
        if(!H1 && !M1 && !H2 && !M2) break;
        minutes = 0;

        if(H1 == H2)
        {
            if(M1 < M2) minutes += (M2 - M1);
            else if(M1 > M2)
            {
                minutes += 23*60;
                while(M1 != M2)
                {
                    minutes += 1;
                    M1 = (M1 + 1)%60;
                }
            }
        }
        else
        {
            minutes += 60 - M1;
            H1 = (H1+1)%24;

            while(H1 != H2)
            {
                minutes+=60;
                H1 = (H1+1)%24;
            }

            minutes += M2;
        }

        cout << minutes << endl;
    }
}
