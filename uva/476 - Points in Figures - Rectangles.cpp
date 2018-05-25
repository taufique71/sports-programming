#include <iostream>
#include <vector>
using namespace std;

struct point
{
    double x;
    double y;
};

struct figure
{
    double UpLeft_x;
    double UpLeft_y;
    double LowRight_x;
    double LowRight_y;
};

vector<figure> fig;
vector<point> pnt;

int isThere(int i , int j);
void calculate();

int main()
{
    char indic;
    point t_point;
    figure t_figure;

    while(cin >> indic)
    {
        if(indic == '*') break;
        else if(indic == 'r')
        {
            cin >> t_figure.UpLeft_x >> t_figure.UpLeft_y >> t_figure.LowRight_x >> t_figure.LowRight_y ;
            fig.push_back(t_figure);
        }
    }

    while(cin >> t_point.x >> t_point.y)
    {
        if((t_point.x == 9999.9) && (t_point.y == 9999.9)) break;
        pnt.push_back(t_point);
    }

    calculate();

    return 0;
}

void calculate()
{
    int l_point = pnt.size();
    int l_figure = fig.size();

    for(int i = 0 ; i < l_point ; i++)
    {
        int flag = 0;
        for(int j = 0 ; j < l_figure ; j++)
        {
            if(isThere(i,j))
            {
                cout << "Point " << i+1 << " is contained in figure " << j+1 << endl;
                flag = 1;
            }
        }

        if(flag == 0) cout << "Point " << i+1 << " is not contained in any figure" << endl;
    }
}

int isThere(int i , int j)
{
    int flagx = 0 , flagy = 0;

    if((pnt[i].x > fig[j].UpLeft_x) && (pnt[i].x < fig[j].LowRight_x)) flagx = 1;
    if((pnt[i].y < fig[j].UpLeft_y) && (pnt[i].y > fig[j].LowRight_y)) flagy = 1;

    return (flagx && flagy);
}
