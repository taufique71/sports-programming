#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    int freq[128];
    char str[10000];
    int max;

    while(gets(str))
    {
        int i = 0;
        max = 0;

        for(int j = 0 ; j < 128 ; j++) freq[j] = 0;

        while(str[i] != NULL)
        {
            if(isalpha(str[i]))
            {
                freq[str[i]]++;
                if(freq[str[i]] > max)
                {
                    max = freq[str[i]];
                }
            }
            i++;
        }

        for(i = 0 ; i < 128 ; i++)
        {
            if(freq[i] == max) printf("%c",i);
        }
        cout << ' ' << max << endl;
    }
    return 0;
}
