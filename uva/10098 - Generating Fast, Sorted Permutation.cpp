#include <iostream>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;

void next(char* (&input))
{
    int i,j;
    stack<char> s;

    for(i = strlen(input)-2 ; i >= 0 ; i--)
    {
        if(input[i] < input[i+1]) break;
    }

    if(i < 0) return;

    for(j = strlen(input)-1 ; j >= 0 ; j--)
    {
        if(input[j] > input[i]) break;
    }

    char temp = input[i];
    input[i] = input[j];
    input[j] = temp;

    j = i+1;

    while(input[j])
    {
        s.push(input[j]);
        j++;
    }

    j = i+1;

    while(!s.empty())
    {
        input[j] = s.top();
        s.pop();
        j++;
    }
}

int main()
{
    int n_case;
    char* input = new char[20];
    char gar[5];
    int flag = 1;

    cin >> n_case;
    gets(gar);
    while(n_case--)
    {
        gets(input);

        sort(input,input+strlen(input));
        do
        {
            cout << input << endl;
            char temp[20];
            strcpy(temp,input);
            next(input);
            if(strcmp(temp,input) == 0) flag = 0;
            else flag = 1;
        }while(flag == 1);
        cout << endl;
    }

    return 0;
}
