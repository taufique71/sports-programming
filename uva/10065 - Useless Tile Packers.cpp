#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <algorithm>
using namespace std;

struct Point
{
    int x;
    int y;
}ref;

vector<Point> points;

double area()
{
    points.push_back(points[0]);
    int n_points = points.size();
    int i;
    double result = 0;

    for(i = 0;i < n_points-1 ; i++)
    {
        result += (points[i].x + points[i+1].x) * (points[i+1].y - points[i].y);
    }
    result = result/2;
    points.pop_back();

    if(result > 0) return result;
    else return (result*(-1));
}

int is_left_special(Point p0, Point p1, Point p2)
{
    long int cross_product = (p1.x - p0.x)*(p2.y - p0.y) - (p2.x - p0.x)*(p1.y - p0.y);
    if(cross_product > 0) return 1;
    else if(cross_product < 0) return -1;
    else return 0;
}

bool is_left(Point p0, Point p1, Point p2)
{
    long int cross_product = (p1.x - p0.x)*(p2.y - p0.y) - (p2.x - p0.x)*(p1.y - p0.y);
    if(cross_product > 0) return true;
    else if(cross_product < 0) return false;
    else
    {
        if((p1.x == p0.x)&&(p1.y == p0.y)) return true;
        else if((p2.x == p0.x)&&(p2.y == p0.y)) return false;
        else return true;
    }
}

bool compare(Point p2, Point p1)
{
    return (!is_left(ref , p1 , p2));
}

void convex_hull()
{
    stack<Point> final;
    int i = 0;
    int count = 0;
    int n_points = points.size();
    int flag = 0;

    final.push(points[i]);
    i++;
    count++;
    if(i < n_points)
    {
        final.push(points[i]);
        i++;
        count++;
    }

    Point p0,p1,p2;

    while((count <= n_points) && (count > 1))
    {
        p2 = points[i%n_points];
        p1 = final.top();
        final.pop();
        p0 = final.top();

        flag = is_left_special(p0,p1,p2);
        if(flag > 0)
        {
            final.push(p1);
            final.push(p2);
            i++;
            count++;
        }
        else if(flag == 0)
        {
            double distance1 = sqrt((p0.x - p1.x)*(p0.x - p1.x) + (p0.y - p1.y)*(p0.y - p1.y));
            double distance2 = sqrt((p0.x - p2.x)*(p0.x - p2.x) + (p0.y - p2.y)*(p0.y - p2.y));
            if(distance1 > distance2) final.push(p1);
            else final.push(p2);
            i++;
            count++;
        }
    }

    points.clear();
    while(!final.empty())
    {
        points.insert(points.begin(),final.top());
        final.pop();
    }

    while(points.size()<3) points.push_back(points[0]);
}

void sort_points()
{
    ref.y = 2147483647;
    ref.x = 2147483647;

    int i = 0,count;
    int n_points = points.size();

    for(i = 0 ; i < n_points ; i++)
    {
        if(points[i].y < ref.y) ref = points[i];
        else if((points[i].y == ref.y)&&(points[i].x < ref.x)) ref = points[i];
    }

    sort(points.begin(),points.end(),compare);
}

int main()
{
    int n_corners;
    int n_tile = 1;
    double area_tile;
    double area_container;
    double result;

    while(cin >> n_corners)
    {
        if(n_corners == 0) break;
        int i = 0;
        Point input;
        points.clear();
        while(i < n_corners)
        {
            cin >> input.x >> input.y;
            points.push_back(input);
            i++;
        }

        area_tile = area();
        sort_points();
        convex_hull();
        area_container = area();
        result = (area_container - area_tile) / area_container * 100;
        cout << "Tile #" << n_tile << endl << "Wasted Space = ";
        printf("%0.2lf",result);
        cout << " %" << endl << endl;

        n_tile++;
    }

    return 0;
}
