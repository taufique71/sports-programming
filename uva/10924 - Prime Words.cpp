#include <iostream>

#define MAX_LETTER 125
#define MAX_SUM 1500

using namespace std;

int map[MAX_LETTER];
int prime[MAX_SUM];

void initialize()
{
    map['a'] = 1;
    map['b'] = 2;
    map['c'] = 3;
    map['d'] = 4;
    map['e'] = 5;
    map['f'] = 6;
    map['g'] = 7;
    map['h'] = 8;
    map['i'] = 9;
    map['j'] = 10;
    map['k'] = 11;
    map['l'] = 12;
    map['m'] = 13;
    map['n'] = 14;
    map['o'] = 15;
    map['p'] = 16;
    map['q'] = 17;
    map['r'] = 18;
    map['s'] = 19;
    map['t'] = 20;
    map['u'] = 21;
    map['v'] = 22;
    map['w'] = 23;
    map['x'] = 24;
    map['y'] = 25;
    map['z'] = 26;
    map['A'] = 27;
    map['B'] = 28;
    map['C'] = 29;
    map['D'] = 30;
    map['E'] = 31;
    map['F'] = 32;
    map['G'] = 33;
    map['H'] = 34;
    map['I'] = 35;
    map['J'] = 36;
    map['K'] = 37;
    map['L'] = 38;
    map['M'] = 39;
    map['N'] = 40;
    map['O'] = 41;
    map['P'] = 42;
    map['Q'] = 43;
    map['R'] = 44;
    map['S'] = 45;
    map['T'] = 46;
    map['U'] = 47;
    map['V'] = 48;
    map['W'] = 49;
    map['X'] = 50;
    map['Y'] = 51;
    map['Z'] = 52;
}

void sieve()
{
    int i,j;
    for(i = 0 ; i < MAX_SUM ; i++) prime[i] = 1;
    prime[0] = 0;

    for(i = 2 ; (i*i) < MAX_SUM;)
    {
        for(j = i + i; j < MAX_SUM ; j = j + i) prime[j] = 0;
        for(j = i+1 ; ( !prime[j] ) && ( (j*j)<MAX_SUM ) ; j++);
        i = j;
    }
}

int main()
{
    char word[25];
    int sumWord;
    int i;

    initialize();
    sieve();

    while(cin >> word)
    {
        sumWord = 0;
        for(i = 0 ; word[i]!= '\0' ; i++) sumWord += map[word[i]];
        if(prime[sumWord] == 1) cout << "It is a prime word." << endl;
        else cout << "It is not a prime word." << endl;
    }

    return 0;
}
