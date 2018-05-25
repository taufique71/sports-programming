#include <iostream>
#include <cstring>

#define ZERO 0

using namespace std;

int main ()
{
    int n;
    char str[5];
    while(cin >> n)
    {
        gets(str);
        if(n == 0) break;
        char input[ZERO + n][26];
        char total[ZERO + n][26];

        int i = 0;
        while(i < n)
        {
            gets(input[i]);
            i++;
        }

        for(i = 0; i < n ; i++) strcpy(total[i],"");

        i = 0;
        int max = 0;

        while(i < n)
        {
            char *side;
            side = strtok(input[i]," B");
            while(side != NULL)
            {
                strcat(total[i],side);
                side = strtok(NULL," B");
            }

            if(strlen(total[i]) > max) max = strlen(total[i]);
            i++;
        }

        int count = 0;

        for(i = 0 ; i < n ; i++)
        {
            count += max - strlen(total[i]);
        }
        cout << count << endl;
    }
    return 0;
}
