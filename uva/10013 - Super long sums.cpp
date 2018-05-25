#include <iostream>

#define ZERO 0

using namespace std;

int main()
{
    int kase;
    int len;
    char str[5];

    cin >> kase;

    while(kase--)
    {
        gets(str);
        cin >> len;
        gets(str);

        int l = 0;
        char num[len + ZERO][4];
        char *res = new char [len + 1];
        res[len] = '\0';
        int car = 0;

        while(l < len)
        {
            gets(num[l]);

            l++;
        }

        for(l = len - 1 ; l >= 0 ; l--)
        {
            res[l] = ((num[l][0] - 48 + num[l][2] - 48 + car) % 10) + 48;
            car = ((num[l][0] - 48 + num[l][2] - 48 + car) / 10);
        }
        cout << res << endl;
        if(kase) cout << endl;
    }

    return 0;
}
