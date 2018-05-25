#include <iostream>

#define ZERO 0

using namespace std;

int main()
{
    int TestCase , NumDays , NumPartys , HartalPrmtr , Count;
    cin >> TestCase;

    while(TestCase--)
    {
        cin >> NumDays;
        int Day[ZERO + NumDays];

        for(int i = 0 ; i < NumDays ; i++) Day[i] = 1;

        cin >> NumPartys;
        while(NumPartys--)
        {
            cin >> HartalPrmtr;
            for(int i = HartalPrmtr - 1; i < NumDays ; i += HartalPrmtr) Day[i] = 0;
        }

        Count = 0;

        for(int i = 0 ; i < NumDays ; i++)
        {
            if(Day[i] == 0)
            {
                if((i % 7 != 5) && (i % 7 != 6)) Count++;
            }
        }
        cout << Count << endl;
    }

    return 0;
}
