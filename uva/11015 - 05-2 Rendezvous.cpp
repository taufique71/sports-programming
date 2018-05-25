#include <iostream>
using namespace std;

const int infinity = 215498798;

int minimum(int a, int b)
{
    if(a <= b) return a;
    else return b;
}

int main()
{
    int n_places,n_ways;
    int i,j,k,a,b,c;
    int n_case = 1;

    while(cin >> n_places >> n_ways)
    {
        if(n_places == 0) break;
        char names[n_places][20];
        int results[n_places];
        int n,m;
        gets(names[0]);
        for(i = 0 ; i < n_places ; i++) gets(names[i]);//cin >> names[i];

        int D[n_places][n_places][n_places];
        int E[n_places][n_places];

        for(i = 0 ; i < n_places ; i++)
        {
            for(j = 0 ; j < n_places ; j++)
            {
                if(i == j) E[i][j] = 0;
                else E[i][j] = infinity;
            }
        }

        for(i = 0 ; i < n_ways ; i++)
        {
            cin >> a >> b >> c;
            E[a-1][b-1] = c;
            E[b-1][a-1] = c;
        }

        for(k = 0 ; k < n_places ; k++)
        {
            for(i = 0 ; i < n_places ; i++)
            {
                for(j = 0 ; j < n_places ; j++)
                {
                    if(k == 0) D[k][i][j] = minimum(E[i][j],E[i][k]+E[k][j]);
                    else D[k][i][j] = minimum(D[k-1][i][j],D[k-1][i][k]+D[k-1][k][j]);
                }
            }
        }

        for(i = 0 ; i < n_places ; i++)
        {
            results[i] = 0;
            for(j = 0 ; j < n_places ; j++) if(D[n_places-1][j][i] != infinity)results[i] += D[n_places-1][j][i];
        }

        n = results[0];
        m = 0;
        for(i = 0 ; i < n_places ; i++)
        {
            if(results[i] < n)
            {
                n = results[i];
                m = i;
            }
        }
        /*for(k = 0 ; k <= n_places ; k++)
        {
            cout << "k = " << k << ':' << endl;
            for(i = 0 ; i < n_places ; i++)
            {
                for(j = 0 ; j < n_places ; j++) cout << D[k][i][j] << "\t\t";
                cout << endl;
            }
            cout << endl << endl;
        }*/

        cout << "Case #" << n_case << " : " << names[m] << endl;
        n_case++;
    }
    return 0;
}
