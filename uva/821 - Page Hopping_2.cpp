#include <iostream>
#include <cstring>
#include <cstdlib>
#include <set>
using namespace std;

const short int infinity = 1234;

int minimum(int a,int b)
{
    if(a <= b) return a;
    else return b;
}

int main()
{
    char input[5000];
    char *tok = new char[10];
    int max_index,i,j,k,n;
    int sum,n_case = 1;
    double result;

    while(gets(input))
    {
        int map[110][110];
        max_index = 0;

        for(i = 0 ; i < 110 ; i++)
        {
            for(j = 0 ; j < 110 ; j++)
            {
                if(i == j) map[i][j] = 0;
                else map[i][j] = infinity;
            }
        }

        set<int> myset;

        tok = strtok(input," ");
        while(tok != NULL)
        {
            i = atoi(tok);
            tok = strtok(NULL," ");
            j = atoi(tok);
            tok = strtok(NULL," ");

            if(i == 0 && j == 0) break;

            if(i > max_index) max_index = i;
            if(j > max_index) max_index = j;

            map[i-1][j-1] = 1;
            myset.insert(i);
            myset.insert(j);
        }

        if(max_index == 0) break;

        short int D[max_index][max_index][max_index];

        for(k = 0 ; k < max_index ; k++)
        {
            for(i = 0 ; i < max_index ; i++)
            {
                for(j = 0 ; j < max_index ; j++)
                {
                    if(k == 0)
                    {
                        if(map[i][k] == infinity || map[k][j] == infinity) D[k][i][j] = map[i][j];
                        else D[k][i][j] = minimum(map[i][j],map[i][k]+map[k][j]);
                    }
                    else
                    {
                        if(D[k-1][i][k] == infinity || D[k-1][k][j] == infinity) D[k][i][j] = D[k-1][i][j];
                        else D[k][i][j] = minimum(D[k-1][i][j],D[k-1][i][k]+D[k-1][k][j]);
                    }
                }
            }
        }

        /*for(k = 0 ; k < max_index ; k++)
        {
            for(i = 0 ; i < max_index ; i++)
            {
                for(j = 0 ; j < max_index ; j++) cout << D[k][i][j] << "\t";
                cout << endl;
            }
            cout << endl << endl;
        }*/

        sum = 0;
        for(i = 0 ; i < max_index ; i++)
        {
            for(j = 0 ; j < max_index ; j++) if(D[max_index-1][i][j] != infinity)sum += D[max_index-1][i][j];
        }
        //cout << sum << ' ' << max_index*(max_index-1) << endl;
        n = myset.size();
        result = (double)sum / (n*(n-1));
        printf("Case %d: average length between pages = %.3lf clicks\n",n_case,result);
        n_case++;
    }
}
