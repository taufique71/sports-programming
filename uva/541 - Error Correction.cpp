#include <iostream>

#define ZERO 0

using namespace std;

int main()
{
    int dim;

    while(cin >> dim)
    {
        if(dim == 0) break;

        int row[ZERO + dim];
        int col[ZERO + dim];

        int row_dim = dim;
        int col_dim = dim;
        int bit;

        int i = 0,j = 0;

        for(i = 0; i < dim ;i++)
        {
            row[i] = 0;
            col[i] = 0;
        }

        i = 0;

        while(i < dim)
        {
            j = 0;

            while(j < dim)
            {
                cin >> bit;
                row[i] += bit;
                col[j] += bit;

                j++;
            }

            i++;
        }

        int track_row = -1;
        int track_col = -1;
        int flag = 1;

        for(i = 0; i < dim ; i++)
        {
            if(row[i] % 2)
            {
                if(track_row < 0) track_row = i;
                else
                {
                    flag = 0;
                }
            }

            if(col[i] % 2)
            {
                if(track_col < 0) track_col = i;
                else
                {
                    flag = 0;
                }
            }
        }

        if((flag == 1) && (track_row < 0) && (track_col < 0)) cout << "OK" << endl;
        else if(flag == 0) cout << "Corrupt" << endl;
        else if((flag = 1) && (track_row >= 0) && (track_col >= 0)) cout << "Change bit " << '(' << track_row+1 << ',' << track_col+1 << ')' << endl;
    }

    return 0;
}
