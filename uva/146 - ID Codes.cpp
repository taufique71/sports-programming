#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

void next(char str[])
{
    int i,j;
    stack<char> stk;

    for(i = strlen(str) - 2 ; i >= 0 ; i--)
    {
        if(str[i] < str[i+1]) break;
    }

    if(i < 0)
    {
        cout << "No Successor" ;
        return;
    }

    for(j = strlen(str) - 1 ; j >= 0 ; j--)
    {
        if(str[j] > str[i]) break;
    }

    int temp = str[i];
    str[i] = str[j];
    str[j] = temp;

    j = i+1;

    while(str[j] != '\0')
    {
        stk.push(str[j]);
        j++;
    }

    j = i+1;

    while(stk.size() > 0)
    {
        str[j] = stk.top();
        stk.pop();
        j++;
    }

    cout << str;

    return;
}

int main()
{
    char str[1000];
    while(gets(str))
    {
        if(str[0] == '#') break;
        next(str);
        cout << endl;
    }
    return 0;
}
