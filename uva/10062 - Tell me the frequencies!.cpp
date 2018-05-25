#include <iostream>
#include <cstdlib>

#define MAX 1050

using namespace std;

int main()
{
    char str[MAX+1];

    int i,j,k,flag = 0;

    int temp_freq;
    char temp_list;

    while(gets(str))
    {
        char list[MAX] = {'\0'};
        int freq[MAX] = {0};

        k = 0;

        for(i = 0 ; str[i] != '\0' ; i++)
        {
            if(str[i] != '\a')
            {
                list[k] = str[i];
                freq[k] = 1;
                for(j = i+1 ; str[j] != '\0' ; j++)
                {
                    if(str[j] == str[i])
                    {
                        freq[k]++;
                        str[j] = '\a';
                    }
                }
                k++;
            }
        }

        for(i = 0 ; i < k ; i++)
        {
            for(j = i + 1 ; j < k ; j++)
            {
                if(freq[i] > freq[j])
                {
                    temp_freq = freq[i];
                    freq[i] = freq[j];
                    freq[j] = temp_freq;

                    temp_list = list[i];
                    list[i] = list[j];
                    list[j] = temp_list;
                }

                else if((freq[i] == freq[j]) && (list[i] < list[j]))
                {
                    temp_freq = freq[i];
                    freq[i] = freq[j];
                    freq[j] = temp_freq;

                    temp_list = list[i];
                    list[i] = list[j];
                    list[j] = temp_list;
                }
            }
        }

        if(flag == 1) cout << endl;

        for(i = 0 ; i < k ; i++) printf("%d %d\n",list[i],freq[i]);

        flag = 1;
    }

    return 0;
}
