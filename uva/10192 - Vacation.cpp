#include <iostream>
#include <cstring>
using namespace std;

char mom[101];
char dad[101];

int num_1;
int num_2;

int LCS()
{
    int table[num_1 + 1][num_2 + 1];

    int i,j;

    for(i = 0; i <= num_1 ; i++) table[i][0] = 0;
    for(j = 0; j <= num_2 ; j++) table[0][j] = 0;

    for(i = 1 ; i <= num_1 ; i++)
    {
        for(j = 1 ; j <= num_2 ; j++)
        {
            if(mom[i - 1] == dad[j - 1]) table[i][j] = table[i - 1][j - 1] + 1;
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
    int kase = 1;

    while(gets(mom))
    {
        if(!strcmp(mom,"#")) break;
        gets(dad);

        num_1 = strlen(mom);
        num_2 = strlen(dad);

        cout << "Case #" << kase << ": you can visit at most " << LCS() << " cities." << endl;
        kase++;
    }

    return 0;
}
