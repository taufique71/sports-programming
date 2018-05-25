#include <iostream>
#include <vector>
using namespace std;

struct Point
{
    double x;
    double y;
};

vector<Point> polygon;

bool insidePolygon(Point p)
{
    int i,j;
    int vertexNum = polygon.size();
    j = vertexNum-1;
    bool result = false;

    for(i = 0 ; i < vertexNum ; i++)
    {
        if(((p.y < polygon[i].y) && (p.y >= polygon[j].y)) || ((p.y >= polygon[i].y) && (p.y < polygon[j].y)))
        {
            if(polygon[i].x == polygon[j].x)
            {
                if(polygon[i].x < p.x) result = !result;
            }
            else
            {
                if(polygon[i].x + (polygon[j].x - polygon[i].x)/(polygon[j].y - polygon[i].y)*(p.y-polygon[i].y) < p.x)
                {
                    result = !result;
                }
            }
        }
        j=i;
    }

    return result;
}

int main()
{
    int setNum;
    int i,j;
    Point temp;

    while(cin >> setNum)
    {
        if(setNum == 0) break;
        i = 0;
        polygon.clear();

        while(i < setNum)
        {
            cin >> temp.x >> temp.y;
            polygon.push_back(temp);
            i++;
        }

        cin >> temp.x >> temp.y;
        if(insidePolygon(temp)) cout << 'T' << endl;
        else cout << 'F' << endl;
    }
}
