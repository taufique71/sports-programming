#include <iostream>
#define TWO 2
using namespace std;

int main()
{
    int n_case;
    int count_case = 1;
    int dimension;
    int i,j;

    cin >> n_case;

    while(count_case <= n_case)
    {
        cin >> dimension;
        char square[dimension+TWO][dimension+TWO];
        for(i = 0 ; i < dimension+TWO ; i++)
        {
            for(j = 0 ; j < dimension+TWO ; j++)
            {
                if(i > 0 && i <= dimension && j > 0 && j <= dimension) cin >> square[i][j];
                else square[i][j] = '*';
            }
        }

        for(i = 1 ; i <= dimension ; i++)
        {
            for(j = 1 ; j <= dimension ; j++)
            {
                if(!isalpha(square[i][j]))
                {
                    for(int k = 0 ; k < 26 ; k++)
                    {
                        if((square[i-1][j] != 'A'+k)&&(square[i+1][j] != 'A'+k)&&(square[i][j-1] != 'A'+k)&&(square[i][j+1] != 'A'+k))
                        {
                            square[i][j] = 'A'+k;
                            break;
                        }
                    }
                }
            }
        }

        cout << "Case " << count_case << ':' << endl;
        for(i = 1 ; i <= dimension ; i++)
        {
            for(j = 1 ; j <= dimension ; j++) cout << square[i][j];
            cout << endl;
        }

        count_case++;
    }

    return 0;
}
