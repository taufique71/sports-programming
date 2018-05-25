#include <iostream>
#include <cmath>
using namespace std;

struct coordinate
{
    int row;
    int col;
};

coordinate towns[100];
int town_count;
const double infinity = 159357;

double dis(coordinate a,coordinate b)
{
    return sqrt((a.col-b.col)*(a.col-b.col)+(a.row-b.row)*(a.row-b.row));
}

double min(double a, double b)
{
    if(a <= b) return a;
    else return b;
}

int main()
{
    int n_case,case_count = 1;
    int n_towns;
    int i,j,k;
    float dis;
    coordinate temp;
    double result;
    bool flag;

    cin >> n_case;

    while(case_count <= n_case)
    {
        cin >> n_towns;

        double world[n_towns][n_towns];

        town_count = 0;
        for(i = 0 ; i < n_towns ; i++)
        {
            cin >> towns[town_count].row >> towns[town_count].col;
            town_count++;
        }

        for(i = 0 ; i < n_towns ; i++)
        {
            for(j = 0 ; j < n_towns ; j++)
            {
                result = sqrt((towns[i].col-towns[j].col)*(towns[i].col-towns[j].col)+(towns[i].row-towns[j].row)*(towns[i].row-towns[j].row));
                if(result <= 10) world[i][j] = result;
                else world[i][j] = infinity;
            }
        }

        for(k = 0 ; k < n_towns ; k++)
        {
            for(i = 0 ; i < n_towns ; i++)
            {
                for(j = 0 ; j < n_towns ; j++)
                {
                    if(world[i][k] == infinity || world[k][j] == infinity) world[i][j] = world[i][j];
                    else world[i][j] = min(world[i][j],world[i][k]+world[k][j]);
                }
            }
        }

        result = 0;
        flag = true;
        for(i = 0 ; i < n_towns ; i++)
        {
            for(j = 0 ; j < n_towns ; j++)
            {
                if(world[i][j] >= infinity)
                {
                    flag = false;
                }
                else if(world[i][j] > result) result = world[i][j];
            }
        }
        printf("Case #%d:\n",case_count);
        if(flag) printf("%0.4lf\n",result);
        else cout << "Send Kurdy" << endl;
        cout << endl;
        case_count++;
    }

    return 0;
}
