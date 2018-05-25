#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
using namespace std;

struct Point
{
    char flag;
    long int x;
    long int y;
}left_ref,right_ref;

vector<Point> points;
const int infinity = 2147483647;

int is_left(Point p0, Point p1, Point p2)
{
    long long int cross_product = (p1.x - p0.x)*(p2.y - p0.y) - (p2.x - p0.x)*(p1.y - p0.y);
    //long double cross_product = (p1.x - p0.x)*(p2.y - p0.y) - (p2.x - p0.x)*(p1.y - p0.y);
    //cout << cross_product << endl;
    if(cross_product > 0) return 1;
    else if(cross_product < 0) return -1;
    else return 0;
}

bool compare(Point p1,Point p2)
{
    int result;
    int flag;
    bool result1;

    //cout << endl;
    //cout << "comparing " << p1.x << ',' << p1.y << "  " << p2.x << ',' << p2.y << endl;

    result = is_left(left_ref,p1,p2);

    if(result > 0) result1 = true;
    else if(result < 0) result1 = false;
    else
    {
        //cout << "They are inline" << endl;
        flag = is_left(right_ref,p2,p1);
        if(flag < 0)
        {
            //cout << p1.x << ',' << p1.y << " is on the right of the line connecting " << right_ref.x << ',' << right_ref.y << "--" << p2.x << ',' << p2.y << endl;
            if((p1.x == left_ref.x)&&(p1.y == left_ref.y))result1 = true;
            else if((p2.x == left_ref.x)&&(p2.y == left_ref.y)) result1 = false;
            else result1 = true;
        }
        else if(flag > 0)
        {
            //cout << p1.x << ',' << p1.y << " is on the left of the line connecting " << right_ref.x << ',' << right_ref.y << "--" << p2.x << ',' << p2.y << endl;
            if((p1.x == left_ref.x)&&(p1.y == left_ref.y))result1 = true;
            else if((p2.x == left_ref.x)&&(p2.y == left_ref.y)) result1 = false;
            else result1 = false;
        }
        else
        {
            //cout << p1.x << ',' << p1.y << " is on the streight line connecting " << right_ref.x << ',' << right_ref.y << "--" << p2.x << ',' << p2.y << endl;
            if((p1.x == left_ref.x)&&(p1.y == left_ref.y))result1 = true;
            else if((p2.x == left_ref.x)&&(p2.y == left_ref.y)) result1 = false;
            else result1 = true;
        }
    }

    //if(result1) cout <<p2.x << ',' << p2.y << " is on the left to the line connecting " << left_ref.x << ',' << left_ref.y << "--" << p1.x << ',' << p1.y << endl;
    //else cout <<p2.x << ',' << p2.y << " is on the right to the line connecting " << left_ref.x << ',' << left_ref.y << "--" << p1.x << ',' << p1.y << endl;
    //cout << endl;

    return result1;
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

        left_ref.x = infinity;
        left_ref.y = infinity;

        right_ref.x = (-1) * infinity;
        right_ref.y = (-1) * infinity;

        while(n_vertex--)
        {
            cin >> input.x >> input.y >> input.flag;
            if(input.flag == 'Y')
            {
                points.push_back(input);

                if(input.x < left_ref.x) left_ref = input;
                else if((input.x == left_ref.x)&&(input.y < left_ref.y)) left_ref = input;

                if(input.x > right_ref.x) right_ref = input;
                else if((input.x == right_ref.x)&&(input.y > right_ref.y)) right_ref = input;
            }
        }
        sort(points.begin(),points.end(),compare);

        n_vertex = points.size();
        cout << n_vertex << endl;
        for(int i = 0 ; i < n_vertex ; i++) cout << points[i].x << ' ' << points[i].y << endl;
    }
}
