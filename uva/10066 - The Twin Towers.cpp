#include <iostream>
using namespace std;

int n1,n2;

int LCS(int tow_1[], int tow_2[])
{
    int table[n1 + 1][n2 + 1];
    int i,j;

    for(i = 0 ; i <= n1 ; i++) table[i][0] = 0;
    for(j = 0 ; j <= n2 ; j++) table[0][j] = 0;

    for(i = 1 ; i <= n1 ; i++)
    {
        for(j = 1 ; j <= n2 ; j++)
        {
            if(tow_1[i] == tow_2[j]) table[i][j] = table[i - 1][j - 1] + 1;
            else
            {
                if(table[i - 1][j] >= table[i][j - 1]) table[i][j] = table[i - 1][j];
                else table[i][j] = table[i][j - 1];
            }
        }
    }

    return table[i - 1][j - 1];
}

int main()
{
    int count = 1;

    while(cin >> n1 >> n2)
    {
        if((n1 == 0) && (n2 == 0)) break;

        int tow_1[n1 + 1];
        int tow_2[n2 + 1];

        tow_1[0] = 0;
        tow_2[0] = 0;

        int i = 1;
        while(i <= n1)
        {
            cin >> tow_1[i];
            i++;
        }

        i = 1;
        while(i <= n2)
        {
            cin >> tow_2[i];
            i++;
        }

        cout << "Twin Towers #" << count << endl;
        cout << "Number of Tiles : " << LCS(tow_1 , tow_2) << endl << endl;

        count++;
    }

    return 0;
}
