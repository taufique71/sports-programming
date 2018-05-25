#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Point
{
    double x;
    double y;
};

struct Figure
{
    char fig;
    double rad;
    vector<Point> details;
};

vector<Figure> total;

int main()
{
    Figure input_f;
    Point input_p;
    int n_figure;
    int i,j;
    int flag = 0;
    char c;

    while(cin >> c)
    {
        if(c == '*') break;

        input_f.details.clear();
        input_f.fig = '\0';
        input_f.rad = 0;

        if(c == 'r')
        {
            input_f.fig = c;
            cin >> input_p.x >> input_p.y;
            input_f.details.push_back(input_p);
            cin >> input_p.x >> input_p.y;
            input_f.details.push_back(input_p);
        }
        else if(c == 't')
        {
            input_f.fig = c;
            cin >> input_p.x >> input_p.y;
            input_f.details.push_back(input_p);
            cin >> input_p.x >> input_p.y;
            input_f.details.push_back(input_p);
            cin >> input_p.x >> input_p.y;
            input_f.details.push_back(input_p);
        }
        else
        {
            input_f.fig = c;
            cin >> input_p.x >> input_p.y;
            input_f.details.push_back(input_p);
            cin >> input_f.rad;
        }

        total.push_back(input_f);
    }

    n_figure = total.size();
    j = 1;

    while(cin >> input_p.x >> input_p.y)
    {
        if((input_p.x == 9999.9) && (input_p.y == 9999.9)) break;

        flag = 0;
        for(i = 0 ; i < n_figure ; i++)
        {
            if(total[i].fig == 'r')
            {
                input_f = total[i];
                if(((input_f.details[0].x < input_p.x)&&(input_f.details[1].x > input_p.x))&&((input_f.details[0].y > input_p.y)&&(input_f.details[1].y < input_p.y)))
                {
                    flag = 1;
                    cout << "Point " << j << " is contained in figure " << i+1 << endl;
                }
            }
            else if(total[i].fig == 't')
            {
                input_f = total[i];
                bool result = false;
                int n_points = input_f.details.size();
                int a,b;
                b = n_points - 1;

                for(a = 0 ; a < n_points ; a++)
                {
                    if(((input_p.y >= input_f.details[a].y)&&(input_p.y < input_f.details[b].y))||((input_p.y < input_f.details[a].y)&&(input_p.y >= input_f.details[b].y)))
                    {
                        if(input_f.details[a].x == input_f.details[b].x)
                        {
                            if(input_p.x > input_f.details[a].x) result = !result;
                        }
                        else
                        {
                            if((input_f.details[a].x + (((input_f.details[b].x - input_f.details[a].x)/(input_f.details[b].y - input_f.details[a].y))*(input_p.y - input_f.details[a].y))) < input_p.x) result = !result;
                        }
                    }
                    b = a;
                }

                if(result)
                {
                    flag = 1;
                    cout << "Point " << j << " is contained in figure " << i+1 << endl;
                }
            }
            else
            {
                input_f = total[i];
                double dis = sqrt((input_p.x - input_f.details[0].x)*(input_p.x - input_f.details[0].x)+(input_p.y - input_f.details[0].y)*(input_p.y - input_f.details[0].y));
                if(dis < input_f.rad)
                {
                    flag = 1;
                    cout << "Point " << j << " is contained in figure " << i+1 << endl;
                }
            }
        }
        if(flag == 0) cout << "Point " << j << " is not contained in any figure" << endl;
        j++;
    }

    return 0;
}
