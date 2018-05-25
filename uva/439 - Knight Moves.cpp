#include <iostream>
#include <queue>

#define MAX 8

using namespace std;

struct square
{
    int col;
    int row;
};

int chess_board[MAX][MAX];

int white = 0;
int red = 1;

char cur[5];
char dest[5];

void init()
{
    int i,j;
    for(i = 0 ; i < MAX ; i++)
    {
        for(j = 0 ; j < MAX ; j++) chess_board[i][j] = white;
    }
}

int traverse()
{
    int moves = 0;
    int  i,j;

    square current;
    square destiny;
    square impos;
    square temp;
    square t;

    current.col = cur[0] - 'a';
    current.row = cur[1] - '1';

    destiny.col = dest[0] - 'a';
    destiny.row = dest[1] - '1';

    impos.col = -1;
    impos.row = -1;

    queue<square> q;

    q.push(current);
    q.push(impos);

    while(q.size() >= 0)
    {
        temp = q.front();
        q.pop();

        if((temp.col != impos.col) || (temp.row != impos.row))
        {
            if((temp.col == destiny.col) && (temp.row == destiny.row)) return moves;

            i = temp.row + 2;
            j = temp.col + 1;
            if(((i >= 0)&&(i < MAX))&&((j >= 0)&&(j < MAX)))
            {
                if(chess_board[i][j] != red)
                {
                    t.row = i;
                    t.col = j;
                    q.push(t);
                    chess_board[i][j] = red;
                }
            }

            i = temp.row + 2;
            j = temp.col - 1;
            if(((i >= 0)&&(i < MAX))&&((j >= 0)&&(j < MAX)))
            {
                if(chess_board[i][j] != red)
                {
                    t.row = i;
                    t.col = j;
                    q.push(t);
                    chess_board[i][j] = red;
                }
            }

            i = temp.row - 2;
            j = temp.col + 1;
            if(((i >= 0)&&(i < MAX))&&((j >= 0)&&(j < MAX)))
            {
                if(chess_board[i][j] != red)
                {
                    t.row = i;
                    t.col = j;
                    q.push(t);
                    chess_board[i][j] = red;
                }
            }

            i = temp.row - 2;
            j = temp.col - 1;
            if(((i >= 0)&&(i < MAX))&&((j >= 0)&&(j < MAX)))
            {
                if(chess_board[i][j] != red)
                {
                    t.row = i;
                    t.col = j;
                    q.push(t);
                    chess_board[i][j] = red;
                }
            }

            i = temp.row + 1;
            j = temp.col + 2;
            if(((i >= 0)&&(i < MAX))&&((j >= 0)&&(j < MAX)))
            {
                if(chess_board[i][j] != red)
                {
                    t.row = i;
                    t.col = j;
                    q.push(t);
                    chess_board[i][j] = red;
                }
            }

            i = temp.row + 1;
            j = temp.col - 2;
            if(((i >= 0)&&(i < MAX))&&((j >= 0)&&(j < MAX)))
            {
                if(chess_board[i][j] != red)
                {
                    t.row = i;
                    t.col = j;
                    q.push(t);
                    chess_board[i][j] = red;
                }
            }

            i = temp.row - 1;
            j = temp.col + 2;
            if(((i >= 0)&&(i < MAX))&&((j >= 0)&&(j < MAX)))
            {
                if(chess_board[i][j] != red)
                {
                    t.row = i;
                    t.col = j;
                    q.push(t);
                    chess_board[i][j] = red;
                }
            }

            i = temp.row - 1;
            j = temp.col - 2;
            if(((i >= 0)&&(i < MAX))&&((j >= 0)&&(j < MAX)))
            {
                if(chess_board[i][j] != red)
                {
                    t.row = i;
                    t.col = j;
                    q.push(t);
                    chess_board[i][j] = red;
                }
            }
        }

        else
        {
            moves++;
            q.push(impos);
        }
    }

}

int main()
{
    while(cin >> cur >> dest)
    {
        init();
        cout << "To get from " << cur << " to " << dest << " takes " << traverse() << " knight moves." << endl;
    }

    return 0;
}
