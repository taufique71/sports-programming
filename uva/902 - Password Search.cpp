#include <iostream>
#include <map>
#include <cstring>

#define MAX 3000000

using namespace std;

char text[MAX];
int length;

char* calculate()
{
    int i,j,text_len,max = 0;
    char* temp = new char[MAX];
    char* result = new char[MAX];
    map<string,int> track;
    map<string,int>::iterator it;

    text_len = strlen(text);
    for(i = 0 ; i <= (text_len - length) ; i++)
    {
        for(j = 0 ; j < length ; j++) temp[j] = text[i+j];
        temp[j] = '\0';
        it = track.find(temp);
        if(it == track.end())
        {
            //track[temp] = 1;
            track.insert(pair<string,int>(temp,1));
            if(max < 1)
            {
                max = 1;
                strcpy(result , temp);
            }
        }
        else
        {
            (it->second)++;
            if(max < it->second)
            {
                max = it->second;
                strcpy(result,temp);
            }
        }
    }

    return result;
}

int main()
{
    while(cin >> length >> text)
    {
        cout << calculate() << endl;
    }
    return 0;
}
