#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    int n_case;
    int max;
    int i;
    char input[210];
    char gar[5];

    cin >> n_case;
    gets(gar);

    while(n_case--)
    {
        gets(input);
        int map[128] = {0};
        i = 0;
        max = 0;
        while(input[i])
        {
            if(isalpha(input[i]))
            {
                char c = tolower(input[i]);
                map[c]++;
                if(map[c] > max) max = map[c];
            }
            i++;
        }

        for(i = 95 ; i < 128 ; i++)
        {
            if(max == map[i]) printf("%c",i);
        }
        cout << endl;
    }

    return 0;
}
