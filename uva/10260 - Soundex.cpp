#include <iostream>
#include <cstring>
using namespace std;

int map[100];

void init()
{
	int i;

	map['A'] = 0;
	map['B'] = 1;
	map['C'] = 2;
	map['D'] = 3;
	map['E'] = 0;
	map['F'] = 1;
	map['G'] = 2;
	map['H'] = 0;
	map['I'] = 0;
	map['J'] = 2;
	map['K'] = 2;
	map['L'] = 4;
	map['M'] = 5;
	map['N'] = 5;
	map['O'] = 0;
	map['P'] = 1;
	map['Q'] = 2;
	map['R'] = 6;
	map['S'] = 2;
	map['T'] = 3;
	map['U'] = 0;
	map['V'] = 1;
	map['W'] = 0;
	map['X'] = 2;
	map['Y'] = 0;
	map['Z'] = 2;
}

void calculate(char word[])
{
	int i;
	int len = strlen(word);
	int track = 0;

	for(i = 0 ; i < len ; i++)
	{
		if((map[word[i]] != 0) && (map[word[i]] != track))
		{
		    cout << map[word[i]];
		    track = map[word[i]];
		}

		else if(map[word[i]] == 0) track = 0;
	}
}

int main()
{
	char word[25];
	init();

	while(gets(word))
	{
		calculate(word);
		cout << endl;
	}

	return 0;
}
