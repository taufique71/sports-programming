#include <iostream>
#include <cstring>
#include <vector>
#include <cctype>

using namespace std;

char oprtr[8]="#$(+-*/";
char val[8]="0123344";
char start = '(';
char end = ')';

vector <char> str;
char blank[] = "";

/********************         Class Declarartion        *********************/

class stack
{
   int arr[100];
   int tos;

public:
    stack()
    {
        tos = 0;
        arr[0] = '#';
    }

    void re_init_stack()
    {
        tos = 0;
        arr[0] = '#';
    }

    void push(char c)
    {
        tos++;
        arr[tos] = c;
    }

    char pop()
    {
        char c;

        c = arr[tos];
        tos--;

        return c;
    }

    int size()
    {
        return (tos + 1);
    }
}s;

/******************        Is Operator Function     ****************/

int is_oprtr(char c)
{
    int i,len = strlen(oprtr);

    for(i = 0; i < len ; i++)
    {
        if(oprtr[i] == c) return 1;
    }

    return 0;
}

/***********************        Precedence Function        ***************************/

int precedence(char c1,char c2)
{
    int i,j;
    int len = strlen(oprtr);

    for(i = 0; i < len; i++)
    {
        if(oprtr[i] == c1) break;
    }

    for(j = 0; j < len; j++)
    {
        if(oprtr[j] == c2) break;
    }

    return (val[i] - val[j]);
}

/***********************      Calculation Function        ***************************/

void calculate(char c)
{
    char ch;

    if(c == start) s.push(c);

    else if(c == end)
    {
        while((ch = s.pop()) != start)
        {
            str.push_back(ch);
        }

    }

    else if(is_oprtr(c))
    {
        while(precedence((ch = s.pop()) , c) >= 0) str.push_back(ch);
        s.push(ch);
        s.push(c);
    }

    else str.push_back(c);
}

/*********************          Function For Printing Output            ******************/

void print()
{
    int len = str.size();
    for(int i = 0; i < len ; i++) cout<<str[i];
}

/********************       Function For Initializing Output String      *******************/

void init()
{
    if(str.size() == 0) return;
    vector<char>::iterator p = str.begin();
    str.erase(p , p + str.size());
}

/*******************      Main Function        *********************/

int main()
{
    int n ;
    char strin[50];

    gets(strin);
    n = atoi(strin);

    gets(strin);

    while(n--)
    {
        init();

        while(gets(strin))
        {
            for(int i = 0; strin[i] ; i++)
            {
                if(strin[i] == '\n')
                {
                    strin[i] = NULL;
                    break;
                }
            }

            if(strlen(strin) == 0) break;

            calculate(strin[0]);
        }

        calculate('$');
        print();
        cout << endl;
        if(n) cout << endl;

        s.re_init_stack();
    }

    return 0;

}
