#include <iostream>
#include <cstring>
using namespace std;

char escape[] = " !\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~\t";
char sen_1[1001];
char sen_2[1001];

int LCS(void)
{
    char list_1[1000][21];
    char list_2[1000][21];
    char *ptr;

    int num_1 = 0;
    ptr = strtok(sen_1 , escape);
    while(ptr != NULL)
    {
        strcpy(list_1[num_1],ptr);
        num_1++;
        ptr = strtok(NULL,escape);
    }

    int num_2 = 0;
    ptr = strtok(sen_2 , escape);
    while(ptr != NULL)
    {
        strcpy(list_2[num_2],ptr);
        num_2++;
        ptr = strtok(NULL,escape);
    }

    int table[num_1 + 1][num_2 + 1];

    int i,j;

    for(i = 0; i <= num_1 ; i++) table[i][0] = 0;
    for(j = 0; j <= num_2 ; j++) table[0][j] = 0;

    for(i = 1 ; i <= num_1 ; i++)
    {
        for(j = 1 ; j <= num_2 ; j++)
        {
            if(strcmp(list_1[i - 1] , list_2[j - 1]) == 0) table[i][j] = table[i - 1][j - 1] + 1;
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
    int i = 1;

    while(gets(sen_1))
    {
        gets(sen_2);
        if((sen_1[0] == '\0') || (sen_2[0] == '\0'))
        {
            printf("%2d" , i);
            cout << ". Blank!" << endl;
        }
        else
        {
            printf("%2d" , i);
            cout << ". Length of longest match: " << LCS() << endl;
        }
        i++;
    }
    return 0;
}
