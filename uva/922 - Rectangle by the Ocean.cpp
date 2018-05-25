#include <iostream>
#include <cmath>

#define MAX_POINT 260

using namespace std;

struct Point
{
    int x;
    int y;
};

struct rectangle
{
    int left_most;
    int right_most;
    int down_most;
    int up_most;
    double area;
    double diff;
}result;

const int pos_infinity = 2147483647;
const int neg_infinity = -2147483647;

int main()
{
    int n_case;
    int n_vertex;
    int i,j,m,n,a,b;
    double temp_area;
    double area;
    int down_most;
    int left_most;
    int up_most;
    int right_most;
    int count;
    Point input;

    cin >> n_case;

    while(n_case--)
    {
        area = 0.00;
        down_most = pos_infinity;
        left_most = pos_infinity;
        up_most = neg_infinity;
        right_most = neg_infinity;
        result.diff = pos_infinity;

        Point points[MAX_POINT];
        cin >> n_vertex;
        i = 0;
        while(i < n_vertex)
        {
            cin >> input.x >> input.y;
            if(input.x < left_most) left_most = input.x;
            if(input.x > right_most) right_most = input.x;
            if(input.y < down_most) down_most = input.y;
            if(input.y > up_most) up_most = input.y;
            points[i] = input;
            i++;
        }
        points[i++] = points[0];

        for(j = 0 ; j < i-1 ; j++) area += (points[j].x + points[j+1].x)*(points[j+1].y - points[j].y);
        area /= 2;
        if(area < 0.00) area *= -1;

        for(i = left_most; i <= right_most ; i++)
        {
            for(j = down_most ; j <= up_most ; j++)
            {
                for(m = i ; m <= right_most ; m++)
                {
                    for(n = j ; n <= up_most ; n++)
                    {
                        temp_area = fabs(m-i)*fabs(n-j);
                        if(fabs(temp_area - area) < result.diff)
                        {
                            count = 0;
                            for(a = 0 ; a < n_vertex ; a++)
                            {
                                if(count >= 3) break;
                                if(i == points[a].x && j == points[a].y) count++;
                                if(i == points[a].x && n == points[a].y) count++;
                                if(m == points[a].x && j == points[a].y) count++;
                                if(m == points[a].x && n == points[a].y) count++;
                            }

                            if(count >= 3)
                            {
                                result.diff = fabs(temp_area - area);
                                result.area = temp_area;

                                result.down_most = j;
                                result.left_most = i;
                                result.up_most = n;
                                result.right_most = m;
                            }
                        }
                    }
                }
            }
        }

        printf("%0.1lf %d %d %d %d\n",area,result.left_most,result.down_most,result.right_most,result.up_most);
    }

    return 0;
}

