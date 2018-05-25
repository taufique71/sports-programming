#include <iostream>
#include <cstring>
using namespace std;

char map[130];

void init()
{
    map['e'] = 'q';
    map['r'] = 'w';
    map['t'] = 'e';
    map['y'] = 'r';
    map['u'] = 't';
    map['i'] = 'y';
    map['o'] = 'u';
    map['p'] = 'i';
    map['['] = 'o';
    map[']'] = 'p';
    map['d'] = 'a';
    map['f'] = 's';
    map['g'] = 'd';
    map['h'] = 'f';
    map['j'] = 'g';
    map['k'] = 'h';
    map['l'] = 'j';
    map[';'] = 'k';
    map['\''] = 'l';
    map['c'] = 'z';
    map['v'] = 'x';
    map['b'] = 'c';
    map['n'] = 'v';
    map['m'] = 'b';
    map[','] = 'n';
    map['.'] = 'm';
    map[' '] = ' ';
    map['E'] = 'q';
    map['R'] = 'w';
    map['T'] = 'e';
    map['Y'] = 'r';
    map['U'] = 't';
    map['I'] = 'y';
    map['O'] = 'u';
    map['P'] = 'i';
    map['D'] = 'a';
    map['F'] = 's';
    map['G'] = 'd';
    map['H'] = 'f';
    map['J'] = 'g';
    map['K'] = 'h';
    map['L'] = 'j';
    map['C'] = 'z';
    map['V'] = 'x';
    map['B'] = 'c';
    map['N'] = 'v';
    map['M'] = 'b';
}

void calculate(char line[])
{
    int i;
    int len = strlen(line);

    for(i = 0; i < len ; i++)
    {
        cout << map[line[i]];
    }
}

int main()
{
    init();

    char line[10000];
    while(gets(line))
    {
        calculate(line);
        cout << endl;
    }
    return 0;
}

