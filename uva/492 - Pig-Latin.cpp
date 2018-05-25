#include <iostream>
#include <cstring>
#include <cctype>
#include <queue>
using namespace std;

char sen[1000000][1000];
long int m,j,k;

int isconsonant(char c);
void calculate_line(char line[]);
void process();
void input();

int main()
{
    input();
    process();
    return 0;
}

void input()
{
    k = 0;
    while(gets(sen[k])) k++;
}

void process()
{
    for(m = 0 ; m < k  ; m++)
    {
        calculate_line(sen[m]);
        cout << endl;
    }
}

void calculate_line(char line[])
{
    long int i = 0;
    queue<char> q;

    while(line[i] != NULL)
    {
        if(isalpha(line[i]))
        {
            q.push(line[i]);
        }

        else
        {
            if(q.size() > 0)
            {
                if(isconsonant(q.front()))
                {
                    q.push(q.front());
                    q.pop();
                }

                q.push('a');
                q.push('y');

                while(q.size() > 0)
                {
                    cout << q.front();
                    q.pop();
                }
                cout << line[i];
            }

            else cout << line[i];
        }
        i++;
    }
}

int isconsonant(char c)
{
    char arr[43] = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";

    int len = strlen(arr);

    for(long int i = 0; i < len ; i++)
    {
        if(arr[i] == c) return 1;
    }

    return 0;
}
