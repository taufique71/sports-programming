#include <iostream>
#include <stack>
#include <queue>
#include <cstring>
#include <cctype>

#define MAX 101

using namespace std;

struct grid
{
    int row;
    int col;
};

char land = 'L';
char water = 'W';

char map[MAX][MAX];

void init()
{
    int i , j;

    for(i = 0 ; i < MAX ; i++)
    {
        for(j = 0 ; j < MAX ; j++) map[i][j] = '*';
    }
}

int get_i(char s[])
{
    char *ans;
    int n;

    ans = strtok(s , " ");
    sscanf(ans , "%d" , &n);

    return n;
}

int get_j(char s[])
{
    char ans[10];
    int i = 0 , j = 0;
    int n;

    while(isdigit(s[i])) i++;
    while(!isdigit(s[i])) i++;
    while(isdigit(s[i]))
    {
        ans[j] = s[i];
        i++;
        j++;
    }
    ans[j] = '\0';
    sscanf(ans , "%d" , &n);

    return n;
}

int flood_fill(int row , int col , char target , char replace)
{
    queue<grid> q;
    stack<grid> s;
    int i , j;
    int count = 0;

    if(map[row][col] != target) return 0;

    grid west;
    grid east;
    grid now;

    now.row = row;
    now.col = col;

    q.push(now);

    while(!q.empty())
    {
        now = q.front();
        q.pop();

        west = now;
        east = now;

        for(i = west.row, j = west.col ; (map[i][j] == target) ; j--);
        west.col = j+1;

        for(i = east.row, j = east.col ; (map[i][j] == target) ; j++);
        east.col = j-1;

        for(i = west.row, j = west.col ; j <= east.col ; j++)
        {
            map[i][j] = replace;
            count++;

            now.row = i;
            now.col = j;
            s.push(now);

            if(map[i-1][j-1] == target)
            {
                now.row = i - 1;
                now.col = j - 1;

                q.push(now);
            }

            if(map[i][j-1] == target)
            {
                now.row = i;
                now.col = j - 1;

                q.push(now);
            }

            if(map[i+1][j-1] == target)
            {
                now.row = i + 1;
                now.col = j - 1;

                q.push(now);
            }

            if(map[i-1][j] == target)
            {
                now.row = i - 1;
                now.col = j;

                q.push(now);
            }

            if(map[i+1][j] == target)
            {
                now.row = i+1;
                now.col = j;

                q.push(now);
            }

            if(map[i-1][j+1] == target)
            {
                now.row = i - 1;
                now.col = j + 1;

                q.push(now);
            }

            if(map[i][j+1] == target)
            {
                now.row = i;
                now.col = j + 1;

                q.push(now);
            }

            if(map[i+1][j+1] == target)
            {
                now.row = i + 1;
                now.col = j + 1;

                q.push(now);
            }
        }
    }

    while(!s.empty())
    {
        now = s.top();
        s.pop();

        map[now.row][now.col] = target;
    }

    return count;
}

int main()
{
    char input[MAX];
    char garbage[10];
    int i , j , kase , flag = 0;

    cin >> kase;
    gets(garbage);
    gets(garbage);
    while(kase--)
    {
        i = 0;
        init();

        while(gets(input))
        {
            if(!isalpha(input[0])) break;
            for(j = 0 ; input[j] ; j++) map[i+1][j+1] = input[j];
            i++;
        }

        i = get_i(input);
        j = get_j(input);
        if(flag == 1) cout << endl;
        cout << flood_fill(i,j,water,land) << endl;
        while(gets(input))
        {
            if(!strcmp(input,"")) break;
            i = get_i(input);
            j = get_j(input);
            cout << flood_fill(i,j,water,land) << endl;
        }
        flag = 1;
    }

    return 0;
}
