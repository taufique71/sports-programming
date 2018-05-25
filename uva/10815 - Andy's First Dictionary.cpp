#include <iostream>
#include <cctype>
#include <cstring>

#define MAX_WORD 250
#define MAX_DIF_WORD 6000
#define MAX_LETTER 100

using namespace std;

char esc[] = "!\"#$%&'()*+,-./0123456789:;<=>?@[\\]^_`{|}~\t\r\n ";
char list[MAX_DIF_WORD][MAX_LETTER];

int n_word = 0;

char* lower(char *gvn)
{
    char *dsr = new char[MAX_WORD];
    int i;

    for(i = 0; gvn[i] != '\0' ; i++)
    {
        dsr[i] = tolower(gvn[i]);
    }
    dsr[i] = '\0';

    return dsr;
}

void add_word(char *word)
{
    int flag = 1;
    int i;

    for(i = 0 ; i < n_word ; i++)
    {
        if(strcmp(word,list[i]) == 0)
        {
            flag = 0;
            break;
        }
    }

    if(flag == 1)
    {
        strcpy(list[i],word);
        n_word++;
    }
}

void swap(int i,int j)
{
    char* temp_word = new char [MAX_LETTER];

    strcpy(temp_word,list[i]);
    strcpy(list[i],list[j]);
    strcpy(list[j],temp_word);
}

int partition(int l,int r)
{
    int i = l - 1;
    int j;

    char* temp_word = new char [MAX_LETTER];
    strcpy(temp_word , list[r]);

    for(j = l ; j < r ; j++)
    {
        if(strcmp(list[j] , list[r]) <= 0)
        {
            i = i + 1;
            swap(i,j);
        }
    }

    swap(i + 1 , r);

    return (i + 1);
}

void q_sort(int l,int r)
{
    int i;

    if(l < r)
    {
        i = partition(l , r);
        q_sort(l , i - 1);
        q_sort(i + 1 , r);
    }
}

void output(void)
{
    int i;
    for(i = 0 ; i < n_word ; i++) cout << list[i] << endl;
}

int main()
{
    char line[MAX_WORD];

    while(gets(line))
    {
        char *ptr = strtok(line,esc);
        while(ptr != NULL)
        {
            strcpy(ptr,lower(ptr));
            add_word(ptr);
            ptr = strtok(NULL,esc);
        }
    }

    q_sort(0 , n_word - 1);
    output();

    return 0;
}
