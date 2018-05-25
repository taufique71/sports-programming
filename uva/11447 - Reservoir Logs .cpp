#include <iostream>
#include <vector>
using namespace std;

struct Point
{
    int x;
    int y;
};

vector<Point> points;
int width;
double ini_pc;
double ini_vol;
double used_vol;
double mid_vol;
double rained_vol;
int final_pc;
double volume;

void calculate_volume()
{
    double area = 0;
    int i;
    int len;
    points.push_back(points[0]);
    len = points.size();

    for(i = 0 ; i < (len-1) ; i++)
    {
        area += (points[i+1].x + points[i].x) * (points[i+1].y - points[i].y);
    }
    area /= 2;

    volume = area * width;
}

int main()
{
    int n_case;
    int n_vertex;
    Point input;

    cin >> n_case;

    while(n_case--)
    {
        cin >> n_vertex;
        points.clear();

        while(n_vertex--)
        {
            cin >> input.x >> input.y;
            points.push_back(input);
        }
        cin >> width;
        cin >> ini_pc >> used_vol >> rained_vol;

        calculate_volume();
        ini_vol = (volume * ini_pc) / 100;

        if(used_vol > ini_vol) cout << "Lack of water. ";

        if(ini_vol <= used_vol) mid_vol = 0.00;
        else mid_vol = ini_vol - used_vol;

        if((mid_vol + rained_vol)>volume) cout << "Excess of water. ";
        if((mid_vol + rained_vol)>volume) cout << "Final percentage: 100%" << endl;
        else
        {
            final_pc = (mid_vol + rained_vol)/volume * 100;
            printf("Final percentage: %d",final_pc);
            cout << '%' << endl;
        }
    }

    return 0;
}
