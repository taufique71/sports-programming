#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Point
{
    double x;
    double y;
}ref,centroid;

vector<Point> points;

int is_left(Point p0,Point p1,Point p2)
{
    double cross_product = (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
    if(cross_product < 0) return -1;
    else if(cross_product > 0) return 1;
    else return 0;
}

bool compare(Point p1, Point p2)
{
    int flag = is_left(ref,p2,p1);
    if(flag > 0) return false;
    else if(flag < 0) return true;
    else
    {
        if(ref.x == p1.x && ref.y == p1.y) return true;
        else if(ref.x == p2.x && ref.y == p2.y) return false;
        else
        {
            double dis1 = sqrt((p1.x - ref.x)*(p1.x - ref.x)+(p1.y - ref.y)*(p1.y - ref.y));
            double dis2 = sqrt((p2.x - ref.x)*(p2.x - ref.x)+(p2.y - ref.y)*(p2.y - ref.y));
            if(dis1 > dis2) return true;
            else return false;
        }
    }
}

double area()
{
    int n_points = points.size();
    int i;
    double a = 0;

    for(i = 0 ; i < n_points-1 ; i++)
    {
        a += (points[i].x+points[i+1].x)*(points[i+1].y - points[i].y);
    }
    if(a < 0) a *= (-1);
    a /= 2;

    return a;
}

void graham_scan()
{
    Point stack[110];
    //stack<Point> s;

    int flag;
    int n_points = points.size();
    int top = 0;
    int i = 0;

    stack[top++] = points[i++];
    stack[top++] = points[i++];

    Point p0,p1,p2;

    while(i < n_points)
    {
        p1 = stack[--top];
        p0 = stack[--top];
        top++;
        p2 = points[i];

        flag = is_left(p0,p1,p2);

        if(flag > 0)
        {
            stack[top++] = p1;
            stack[top++] = p2;
            i++;
        }
        else if(flag == 0)
        {
            double dis1 = sqrt((p1.x - p0.x)*(p1.x - p0.x)+(p1.y - p0.y)*(p1.y - p0.y));
            double dis2 = sqrt((p2.x - p0.x)*(p2.x - p0.x)+(p2.y - p0.y)*(p2.y - p0.y));
            if(dis2 > dis1) stack[top++] = p2;
            else stack[top++] = p1;
            i++;
        }
    }

    points.clear();
    while(top)
    {
        points.insert(points.begin(),stack[--top]);
    }
}

void get_centroid(double A)
{
    int n_points = points.size();
    int i;
    double c_x = 0;
    double c_y = 0;

    for(i = 0 ; i < (n_points-1) ; i++)
    {
        c_x += (points[i].x+points[i+1].x)*(points[i].x*points[i+1].y - points[i+1].x*points[i].y);
        c_y += (points[i].y+points[i+1].y)*(points[i].x*points[i+1].y - points[i+1].x*points[i].y);
    }
    c_x /= (6*A);
    c_y /= (6*A);

    centroid.x = c_x;
    centroid.y = c_y;
}

int main()
{
    int n_points;
    double A;
    Point input;

    while(cin >> n_points)
    {
        if(n_points < 3) break;
        points.clear();
        ref.x = 2147483647;
        ref.y = 2147483647;
        while(n_points--)
        {
            cin >> input.x >> input.y;
            points.push_back(input);
            if(input.y < ref.y) ref = input;
            else if((input.y == ref.y)&&(input.x < ref.x)) ref = input;
        }

        sort(points.begin(),points.end(),compare);
        points.push_back(points[0]);
        A = area();
        graham_scan();
        get_centroid(A);
        printf("%.3lf %.3lf\n",centroid.x,centroid.y);
    }

    return 0;
}
