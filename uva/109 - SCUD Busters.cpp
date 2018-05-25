#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <algorithm>
using namespace std;

struct Location
{
    double x;
    double y;
}ref;

vector<Location> kingdom;
vector< vector<Location> > country;
vector<double> area;
int infinity = 2147483647;

int is_left_special(Location l0, Location l1, Location l2)
{
    double cross_product = (l1.x - l0.x)*(l2.y - l0.y) - (l2.x - l0.x)*(l1.y - l0.y);
    if(cross_product > 0) return 1;
    else if(cross_product < 0) return -1;
    else return 0;
}

bool is_left(Location l0, Location l1, Location l2)
{
    double cross_product = (l1.x - l0.x)*(l2.y - l0.y) - (l2.x - l0.x)*(l1.y - l0.y);
    if(cross_product > 0) return true;
    else if(cross_product < 0) return false;
    else
    {
        if((l1.x == l0.x)&&(l1.y == l0.y)) return true;
        else if((l2.x == l0.x)&&(l2.y == l0.y)) return false;
        else return true;
    }
}

bool compare(Location l2, Location l1)
{
    return (!is_left(ref,l1,l2));
}

void sort_kingdom()
{
    ref.x = infinity;
    ref.y = infinity;

    int n_location = kingdom.size();
    int i,j;

    for(i = 0 ; i < n_location ; i++)
    {
        if(kingdom[i].y < ref.y) ref = kingdom[i];
        else if((kingdom[i].y == ref.y) && (kingdom[i].x < ref.x)) ref = kingdom[i];
    }

    sort(kingdom.begin(),kingdom.end(),compare);
}

void graham_scan()
{
    stack<Location> final;
    int left_flag = 0;
    int i = 0;
    int count = 0;
    int n_location = kingdom.size();

    final.push(kingdom[i]);
    i++;
    count++;

    if(count < n_location)
    {
        final.push(kingdom[i]);
        i++;
        count++;
    }

    Location l0,l1,l2;

    while((count < n_location)&&(count > 1))
    {
        l2 = kingdom[i];
        l1 = final.top();
        final.pop();
        l0 = final.top();

        left_flag = is_left_special(l0,l1,l2);

        if(left_flag > 0)
        {
            final.push(l1);
            final.push(l2);
            i++;
            count++;
        }
        else if(left_flag == 0)
        {
            double dist1 = sqrt((l1.x - l0.x)*(l1.x - l0.x) + (l1.y - l0.y)*(l1.y - l0.y));
            double dist2 = sqrt((l2.x - l0.x)*(l2.x - l0.x) + (l2.y - l0.y)*(l2.y - l0.y));
            if(dist1 >= dist2) final.push(l1);
            else final.push(l2);
            i++;
            count++;
        }
    }

    kingdom.clear();
    while(!final.empty())
    {
        kingdom.insert(kingdom.begin(),final.top());
        final.pop();
    }
}

double calculate_area()
{
    int i;
    kingdom.push_back(kingdom[0]);
    int n_location = kingdom.size();
    double result = 0;

    for(i = 0 ; i < n_location-1 ; i++) result += (kingdom[i].x + kingdom[i+1].x)*(kingdom[i+1].y - kingdom[i].y);

    kingdom.pop_back();
    if(result < 0) result *= -1;

    return (result / 2);
}

bool check_corners(int a,Location l)
{
    int n_location = country[a].size();
    int i;
    for(i = 0 ; i < n_location ; i++)
    {
        if((l.x == country[a][i].x) && (l.y == country[a][i].y)) return true;
    }
    return false;
}

bool inside_kingdom(int a , Location l)
{
    bool result = false;
    int n_vertex = country[a].size();
    int i = 0;
    int j = n_vertex - 1;

    for(i = 0 ; i < n_vertex ; i++)
    {
        if(((l.y <= country[a][i].y)&&(l.y > country[a][j].y))||((l.y > country[a][i].y)&&(l.y <= country[a][j].y)))
        {
            if(country[a][i].x == country[a][j].x)
            {
                if(country[a][i].x < l.x) result = !result;
            }
            else if((country[a][i].x + (country[a][j].x - country[a][i].x)/(country[a][j].y - country[a][i].y)* (l.y - country[a][i].y)) < l.x) result = !result;
        }
        j = i;
    }

    return result;
}

int main()
{
    int n_location;
    int n_kingdom;
    int i,j;
    double dark_area = 0;
    Location input;
    country.clear();

    while(cin >> n_location)
    {
        if(n_location < 0) break;
        i = 0;
        kingdom.clear();
        while(i < n_location)
        {
            cin >> input.x >> input.y;
            kingdom.push_back(input);
            i++;
        }
        sort_kingdom();
        graham_scan();
        country.push_back(kingdom);
        area.push_back(calculate_area());
    }

    n_kingdom = country.size();

    while(cin >> input.x >> input.y)
    {
        for(i = 0 ; i < n_kingdom ; i++)
        {
            if(inside_kingdom(i,input))
            {
                dark_area += area[i];
                area[i] = 0;
                break;
            }
        }
    }

    printf("%0.2lf\n",dark_area);

    return 0;
}
