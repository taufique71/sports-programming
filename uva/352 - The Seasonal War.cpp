#include <iostream>
#include <queue>
using namespace std;

char image[30][30];

char white = '0';
char red = '1';

struct pixel
{
    char row;
    char col;
};

void re_init()
{
    int i , j;

    for(i = 0 ; i < 30 ; i++)
    {
        for(j = 0 ; j < 30 ; j++) image[i][j] = 0;
    }
}

void flood_fill(int row , int col , char target , char replace)
{
    queue<pixel> q;
    int i , j;

    if(image[row][col] != target) return;

    pixel centre;
    pixel west;
    pixel east;
    pixel now;

    now.row = row;
    now.col = col;

    q.push(now);

    while(!q.empty())
    {
        now = q.front();
        q.pop();

        west = now;
        east = now;

        for(i = west.row, j = west.col ; (image[i][j] == target) ; j--);
        west.col = j+1;

        for(i = east.row, j = east.col ; (image[i][j] == target) ; j++);
        east.col = j-1;

        for(i = west.row, j = west.col ; j <= east.col ; j++)
        {
            image[i][j] = replace;

            if(image[i-1][j-1] == target)
            {
                now.row = i - 1;
                now.col = j - 1;

                q.push(now);
            }

            if(image[i][j-1] == target)
            {
                now.row = i;
                now.col = j - 1;

                q.push(now);
            }

            if(image[i+1][j-1] == target)
            {
                now.row = i + 1;
                now.col = j - 1;

                q.push(now);
            }

            if(image[i-1][j] == target)
            {
                now.row = i - 1;
                now.col = j;

                q.push(now);
            }

            if(image[i+1][j] == target)
            {
                now.row = i+1;
                now.col = j;

                q.push(now);
            }

            if(image[i-1][j+1] == target)
            {
                now.row = i - 1;
                now.col = j + 1;

                q.push(now);
            }

            if(image[i][j+1] == target)
            {
                now.row = i;
                now.col = j + 1;

                q.push(now);
            }

            if(image[i+1][j+1] == target)
            {
                now.row = i + 1;
                now.col = j + 1;

                q.push(now);
            }
        }
    }

    return;
}

int main()
{
    int dim;
    int i , j , k;
    int kase = 1;
    char input[30];

    while(cin >> dim)
    {
        i = 0;
        while(i < dim)
        {
            cin >> input;
            for(j = 0 ; input[j] ; j++)
            {
                image[i+1][j+1] = input[j];
            }
            i++;
        }

        int count = 0;

        for(i = 1 ; i <= dim ; i++)
        {
            for(j = 1 ; j <= dim ; j++)
            {
                if(image[i][j] == red)
                {
                    count++;
                    flood_fill(i , j , red , white);
                }
            }
        }

        cout << "Image number " << kase << " contains " << count << " war eagles." << endl;
        kase++;
    }

    return 0;
}
