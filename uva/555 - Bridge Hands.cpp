#include <iostream>
#include <cctype>
#include <algorithm>
#include <vector>
using namespace std;

class card
{
public:
    char suit;
    char symbol;
};

bool compare(card a,card b)
{
    if(a.suit!=b.suit)
    {
        if(a.suit == 'S' && b.suit == 'H') return true;
        else if(a.suit == 'H' && b.suit == 'S') return false;
        else return (a.suit < b.suit);
    }
    else
    {
        if(isdigit(a.symbol)&&isdigit(b.symbol))
        {
            if(a.symbol < b.symbol) return true;
            else return false;
        }
        else if(isdigit(a.symbol)&&!isdigit(b.symbol)) return true;
        else if(!isdigit(a.symbol)&&isdigit(b.symbol)) return false;
        else
        {
            if(a.symbol == 'T' && b.symbol == 'J') return true;
            else if(a.symbol == 'J' && b.symbol == 'T') return false;
            else if(a.symbol == 'T' && b.symbol == 'Q') return true;
            else if(a.symbol == 'Q' && b.symbol == 'T') return false;
            else if(a.symbol == 'T' && b.symbol == 'K') return true;
            else if(a.symbol == 'K' && b.symbol == 'T') return false;
            else if(a.symbol == 'T' && b.symbol == 'A') return true;
            else if(a.symbol == 'A' && b.symbol == 'T') return false;
            else if(a.symbol == 'J' && b.symbol == 'Q') return true;
            else if(a.symbol == 'Q' && b.symbol == 'J') return false;
            else if(a.symbol == 'J' && b.symbol == 'K') return true;
            else if(a.symbol == 'K' && b.symbol == 'J') return false;
            else if(a.symbol == 'J' && b.symbol == 'A') return true;
            else if(a.symbol == 'A' && b.symbol == 'J') return false;
            else if(a.symbol == 'Q' && b.symbol == 'K') return true;
            else if(a.symbol == 'K' && b.symbol == 'Q') return false;
            else if(a.symbol == 'Q' && b.symbol == 'A') return true;
            else if(a.symbol == 'A' && b.symbol == 'Q') return false;
            else if(a.symbol == 'K' && b.symbol == 'A') return true;
            else if(a.symbol == 'A' && b.symbol == 'K') return false;
        }
    }
}

int main()
{
    char starter;
    int i,j,s,deck_count;
    card temp;
    while(cin >> starter)
    {
        if(starter == '#') break;
        else if(starter == 'E') s = 0;
        else if(starter == 'S') s = 1;
        else if(starter == 'W') s = 2;
        else if(starter == 'N') s = 3;

        vector<card> east;
        vector<card> south;
        vector<card> west;
        vector<card> north;

        deck_count = 52;
        while(deck_count--)
        {
            s = (s+1)%4;
            cin >> temp.suit >> temp.symbol;
            if(s == 0) east.push_back(temp);
            else if(s == 1) south.push_back(temp);
            else if(s == 2) west.push_back(temp);
            else if(s == 3) north.push_back(temp);
        }

        sort(east.begin(),east.end(),compare);
        sort(south.begin(),south.end(),compare);
        sort(west.begin(),west.end(),compare);
        sort(north.begin(),north.end(),compare);

        for(i = 0 ; i < 4 ; i++)
        {
            if(i == 0)
            {
                printf("S:");
                for(j = 0 ; j < 13 ; j++) printf(" %c%c",south[j].suit,south[j].symbol);
                cout << endl;
            }
            else if(i == 1)
            {
                printf("W:");
                for(j = 0 ; j < 13 ; j++) printf(" %c%c",west[j].suit,west[j].symbol);
                cout << endl;
            }
            else if(i == 2)
            {
                printf("N:");
                for(j = 0 ; j < 13 ; j++) printf(" %c%c",north[j].suit,north[j].symbol);
                cout << endl;
            }
            else if(i == 3)
            {
                printf("E:");
                for(j = 0 ; j < 13 ; j++) printf(" %c%c",east[j].suit,east[j].symbol);
                cout << endl;
            }
        }
    }
    return 0;
}
