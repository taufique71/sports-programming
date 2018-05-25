#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> num;
vector<int> den;

void gen_num();
void gen_den();
void generate();

int track_num = 1;
int track_den = 2;

int main()
{
    long int term;
    generate();
    while(cin >> term)
    {
        cout << "TERM " << term << " IS " << num[term - 1] << '/' << den[term - 1] << endl;
    }
    return 0;
}

void generate()
{
    while(num.size() < 10000000)
    {
        gen_num();
    }

    while(den.size() < 10000000)
    {
        gen_den();
    }
}

void gen_num()
{
    stack<int> s;
    int i;
    for(i = 1; i < track_num ; i++)
    {
        num.push_back(i);
        s.push(i);
    }

    num.push_back(i);

    while(s.size() > 0)
    {
        num.push_back(s.top());
        s.pop();
    }

    track_num += 2;
}

void gen_den()
{
    stack<int> s;
    int i;
    for(i = 1; i < track_den ; i++)
    {
        den.push_back(i);
        s.push(i);
    }

    den.push_back(i);

    while(s.size() > 0)
    {
        den.push_back(s.top());
        s.pop();
    }

    track_den += 2;
}
