#include <iostream>
#include <string>
#include <map>
using namespace std;

int is_consonant(char c)
{
    if((c == 'a')||(c == 'e')||(c == 'i')||(c == 'o')||(c == 'u')) return 0;
    else return 1;
}

int main()
{
    int n_line , n_check;
    string singular,plural;
    char gar[5];

    map<string,string> irregular;
    map<string,string>::iterator it;
    pair<map<string,string>::iterator,bool> p;

    cin >> n_line >> n_check;
    gets(gar);

    while(n_line--)
    {
        cin >> singular >> plural;
        irregular.insert(pair<string,string>(singular,plural));
    }
    while(n_check--)
    {
        cin >> singular;
        int last = singular.length()-1;
        it = irregular.find(singular);
        if(it != irregular.end()) cout << it->second << endl;
        else
        {
            if(singular[last] == 'y' && is_consonant(singular[last-1])) singular.replace(last,1,"ies");
            else if((singular[last] == 's') || (singular[last] == 'x') || (singular[last] == 'o') || (singular[last-1] == 'c' && singular[last] == 'h') || (singular[last-1] == 's' && singular[last] == 'h')) singular.append("es");
            else singular.append("s");
            cout << singular << endl;
        }
    }
    return 0;
}
