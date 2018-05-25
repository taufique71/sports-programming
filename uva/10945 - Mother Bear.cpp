#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int is_pallindrome(char str[])
{
    int i,j;

    for(i = 0 , j = strlen(str)-1;i < j ; i++,j--)
    {
        if(str[i] != str[j]) return 0;
    }
    return 1;
}

int main()
{
    char input[10000];

    while(gets(input))
    {
        if(strcmp(input,"DONE") == 0) break;

        char* temp;
        char* filtered = new char[10000];
        filtered[0] = '\0';
        temp = strtok(input," ?!,.");

        while(temp != NULL)
        {
            for(int i = 0;temp[i];i++) temp[i] = tolower(temp[i]);
            strcat(filtered,temp);
            temp = strtok(NULL," ?!,.");
        }

        if(is_pallindrome(filtered)) printf("You won't be eaten!\n");
        else printf("Uh oh..\n");
    }
}
