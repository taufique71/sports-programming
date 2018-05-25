#include <iostream>
#include <vector>
using namespace std;

int main()
{
    char a[1050];
    char b[1050];
    int i , j ;

    while(gets(a))
    {
        gets(b);

        int track_a[130] = {0};
        int track_b[130] = {0};

        for(i = 0 , j = 0 ; (a[i] != '\0')||(b[j] != '\0') ;)
        {
            if(a[i] != '\0')
            {
                track_a[a[i]]++;
                i++;
            }
            if(b[j] != '\0')
            {
                track_b[b[j]]++;
                j++;
            }
        }

        vector<char> result;

        for(i = 0 ; i < 130 ; i++)
        {
            if(track_a[i] > 0)
            {
                if(track_b[i] > 0)
                {
                    for(j = 0 ; (j < track_a[i])&&(j < track_b[i]) ; j++)
                    result.push_back(i);
                }
            }
        }

        j = result.size();
        for(i = 0 ; i < j ; i++) cout << result[i];
        cout << endl;
    }

    return 0;
}
