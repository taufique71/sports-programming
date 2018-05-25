#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char sen[105][105];
    int i,j,k = 0;
    int max = 0;

    while(gets(sen[k]))
    {
        if(strlen(sen[k]) > max) max = strlen(sen[k]);
        k++;
    }

    for(i = 0; i < k ; i++)
    {
        if(strlen(sen[i]) < max)
        {
            j = strlen(sen[i]);
            while(j < max)
            {
                sen[i][j] = ' ';
                j++;
            }
            sen[i][j] = '\0';
        }
    }

    for(i = 0; i < max ; i++)
    {
        for(j = k -1 ; j >= 0; j--)
        {
            cout << sen[j][i];
        }
        cout << endl;
    }

    return 0;
}
