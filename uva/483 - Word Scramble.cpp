#include <iostream>
#include <cstring>
using namespace std;

void reverse(char *word)
{
    int i;
    for(i = strlen(word) - 1; i >=0 ; i--)
    {
        cout << word[i];
    }

    return;
}

void calculate(char line[])
{
    char *word;

    word = strtok(line," \t");

    while(word != NULL)
    {
        reverse(word);
        word = strtok(NULL," \t");

        if(word != NULL) cout << ' ';
    }

}

int main()
{
    char line[10000];

    while(gets(line))
    {
        calculate(line);
        cout << endl;
    }

    return 0;
}
