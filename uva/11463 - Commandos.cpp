#include <iostream>
using namespace std;

const short int infinity = 1937;

short int minimum(short a,short b)
{
    if(a <= b) return a;
    else return b;
}

int main()
{
    int n_case;
    int n_buildings;
    int n_roads;
    int case_count = 1;
    int i,j,k,start,end;
    int result;

    cin >> n_case;
    while(case_count <= n_case)
    {
        cin >> n_buildings;
        cin >> n_roads;

        short int map[n_buildings][n_buildings];
        short int floyd[n_buildings][n_buildings][n_buildings];

        for(i = 0 ; i < n_buildings ; i++)
        {
            for(j = 0 ; j < n_buildings ; j++)
            {
                if(i == j) map[i][j] = 0;
                else map[i][j] = infinity;
            }
        }

        for(i = 0 ; i < n_roads ; i++)
        {
            cin >> j >> k;
            map[j][k] = 1;
            map[k][j] = 1;
        }
        cin >> start >> end;

        for(k = 0 ; k < n_buildings ; k++)
        {
            for(i = 0 ; i < n_buildings ; i++)
            {
                for(j = 0 ; j < n_buildings ; j++)
                {
                    if(k == 0) floyd[k][i][j] = minimum(map[i][j],map[i][k]+map[k][j]);
                    else floyd[k][i][j] = minimum(floyd[k-1][i][j],floyd[k-1][i][k]+floyd[k-1][k][j]);
                }
            }
        }
        /*cout << endl;
        for(i = 0 ; i < n_buildings ; i++)
        {
            for(j = 0 ; j < n_buildings ; j++) cout << map[i][j] << '\t';
            cout << endl;
        }
        cout << endl<< endl;*/

        /*for(k = 0 ; k < n_buildings ; k++)
        {
            for(i = 0 ; i < n_buildings ; i++)
            {
                for(j = 0 ; j < n_buildings ; j++) cout << floyd[k][i][j] << '\t';
                cout << endl;
            }
            cout << endl << endl;
        }*/

        result = 0;
        for(k = 0 ; k < n_buildings ; k++)
        {
            if(floyd[n_buildings-1][start][k] != infinity && floyd[n_buildings-1][k][end] != infinity)
            {
                if(floyd[n_buildings-1][start][k]+floyd[n_buildings-1][k][end] > result) result = floyd[n_buildings-1][start][k]+floyd[n_buildings-1][k][end];
            }
        }

        printf("Case %d: %d\n",case_count,result);
        case_count++;
    }
}
