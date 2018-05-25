#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <queue>
#define MAX 400000
using namespace std;

class node
{
public:
    char grid[4][4];
    int d;
    int ser;

    void init(char t[4][4])
    {
        for(int i = 0 ; i < 3 ; i++) strcpy(grid[i],t[i]);
    }
};

string path[MAX];
int step[MAX];
map<string,int> m;
int c;
char st[4][4];
string s = "123456789";

void precalc()
{
    m.clear();
    c = 1;
    m[s] = c++;
    path[m[s]] = "";
    step[m[s]] = 0;

    node start;
    node temp;
    char ch;
    start.d = 0;
    start.ser = 1;
    start.init(st);
    queue<node> q;
    q.push(start);

    while(!q.empty())
    {
        start = q.front();
        q.pop();

        for(int i = 0 ; i < 3 ; i++)
        {
            temp.init(start.grid);
            ch = temp.grid[i][0];
            temp.grid[i][0] = temp.grid[i][1];
            temp.grid[i][1] = temp.grid[i][2];
            temp.grid[i][2] = ch;

            s = temp.grid[0];
            s += temp.grid[1];
            s += temp.grid[2];

            if(m[s] < 1)
            {
                m[s] = c;
                step[c] = start.d + 1;
                if(i == 0) path[c] = "H1" + path[start.ser];
                else if(i == 1) path[c] = "H2" + path[start.ser];
                else if(i == 2) path[c] = "H3" + path[start.ser];
                temp.d = step[c];
                temp.ser = c;
                q.push(temp);
                c++;
            }
        }

        for(int i = 0 ; i < 3 ; i++)
        {
            temp.init(start.grid);
            ch = temp.grid[2][i];
            temp.grid[2][i] = temp.grid[1][i];
            temp.grid[1][i] = temp.grid[0][i];
            temp.grid[0][i] = ch;

            s = temp.grid[0];
            s += temp.grid[1];
            s += temp.grid[2];

            if(m[s] < 1)
            {
                m[s] = c;
                step[c] = start.d + 1;
                if(i == 0) path[c] = "V1" + path[start.ser];
                else if(i == 1) path[c] = "V2" + path[start.ser];
                else if(i == 2) path[c] = "V3" + path[start.ser];
                temp.d = step[c];
                temp.ser = c;
                q.push(temp);
                c++;
            }
        }
    }
}

int main()
{
    strcpy(st[0],"123");
    strcpy(st[1],"456");
    strcpy(st[2],"789");

    precalc();
    char input[10];
    while(cin >> input[0])
    {
        if(input[0] == '0') break;
        cin >> input[1] >> input[2] >> input[3] >> input[4] >> input[5] >> input[6] >> input[7] >> input[8];
        input[9] = '\0';

        s = input;

        if(m[s] > 0)
        {
            cout << step[m[s]] << ' ' << path[m[s]] << endl;
        }
        else cout << "Not solvable" << endl;
    }
    return 0;
}
