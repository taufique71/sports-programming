#include <iostream>
#include <cmath>
using namespace std;

struct shade
{
    int from;
    int to;
};

struct point
{
    int x;
    int y;
};

int cross_product(point s,point e,point p1,point p2,point p3,point p4)
{
    int r1 = (s.x - p1.x)*(e.y - p1.y) - (s.y - p1.y)*(e.x - p1.x);
    int r2 = (s.x - p2.x)*(e.y - p2.y) - (s.y - p2.y)*(e.x - p2.x);
    int r3 = (s.x - p3.x)*(e.y - p3.y) - (s.y - p3.y)*(e.x - p3.x);
    int r4 = (s.x - p4.x)*(e.y - p4.y) - (s.y - p4.y)*(e.x - p4.x);

    //cout << r1 << ' ' << r2 << ' ' << r3 << ' ' << r4 << endl;

    int pos_count = 0;
    int neg_count = 0;

    if(r1 < 0) neg_count++;
    else if(r1 > 0) pos_count++;
    if(r2 < 0) neg_count++;
    else if(r2 > 0) pos_count++;
    if(r3 < 0) neg_count++;
    else if(r3 > 0) pos_count++;
    if(r4 < 0) neg_count++;
    else if(r4 > 0) pos_count++;

    //cout << pos_count << ' ' << neg_count << endl;

    if(pos_count == 4 || neg_count == 4) return 1;
    else return 0;
}

int check_shade(point s,point e,point p0,point p1)
{
    bool flag_x;
    bool flag_y;
    shade s_r_x;
    shade s_r_y;
    shade s_l_x;
    shade s_l_y;

    if(s.x < e.x)
    {
        s_l_x.from = s.x;
        s_l_x.to = e.x;
    }
    else
    {
        s_l_x.from = e.x;
        s_l_x.to = s.x;
    }

    if(s.y < e.y)
    {
        s_l_y.from = s.y;
        s_l_y.to = e.y;
    }
    else
    {
        s_l_y.from = e.y;
        s_l_y.to = s.y;
    }

    s_r_x.from = p0.x;
    s_r_x.to = p1.x;
    s_r_y.from = p0.y;
    s_r_y.to = p1.y;

    //cout << '(' << s_l_x.from << ',' << s_l_x.to << ')' << "  " << '(' << s_l_y.from << ',' << s_l_y.to << ')' << endl;
    //cout << '(' << s_r_x.from << ',' << s_r_x.to << ')' << "  " << '(' << s_r_y.from << ',' << s_r_y.to << ')' << endl;

    if(s_l_x.from >= s_r_x.from)
    {
        if(s_l_x.from <= s_r_x.to)
        {
            //cout << "f1";
            flag_x = true;
        }
        else
        {
            //cout << '1';
            flag_x = false;
        }
    }
    else
    {
        if(s_l_x.to >= s_r_x.from)
        {
            //cout << "f2";
            flag_x = true;
        }
        else
        {
            //cout << '2';
            flag_x = false;
        }
    }

    if(s_l_y.from >= s_r_y.from)
    {
        if(s_l_y.from <= s_r_y.to)
        {
            //cout << "t1";
            flag_y = true;
        }
        else
        {
            //cout << '3';
            flag_y = false;
        }
    }
    else
    {
        if(s_l_y.to >= s_r_y.from)
        {
            //cout << "t2";
            flag_y = true;
        }
        else
        {
            //cout << '4';
            flag_y = false;
        }
    }

    return (flag_x&&flag_y);
}

int main()
{
    int x_start,y_start,x_end,y_end;
    int x_left,y_top,x_right,y_bottom;
    int n_case;
    int temp;
    point p1,p2,p3,p4;
    point s,e;

    cin >> n_case;

    while(n_case--)
    {
        cin >> x_start >> y_start >> x_end >> y_end >> x_left >> y_top >> x_right >> y_bottom;

        if(x_left > x_right)
        {
            temp = x_left;
            x_left = x_right;
            x_right = temp;
        }

        if(y_top < y_bottom)
        {
            temp = y_top;
            y_top = y_bottom;
            y_bottom = temp;
        }

        p1.x = x_left;
        p1.y = y_top;
        p2.x = x_left;
        p2.y = y_bottom;
        p3.x = x_right;
        p3.y = y_bottom;
        p4.x = x_right;
        p4.y = y_top;

        s.x = x_start;
        s.y = y_start;
        e.x = x_end;
        e.y = y_end;

        if(cross_product(s,e,p1,p2,p3,p4) == 1)
        {
            //cout << "m1";
            cout << "F" << endl;
        }
        else
        {
            if(check_shade(s,e,p2,p4)) cout << "T" << endl;
            else
            {
                //cout << "m2";
                cout << "F" << endl;
            }
        }
    }

    return 0;
}
