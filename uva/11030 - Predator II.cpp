#include <iostream>
#include <vector>
using namespace std;

struct Point
{
    double x;
    double y;
};

vector<Point> compartment;
vector < vector<Point> > room;

bool insideCompartment(int a, Point p)
{
    int n_vertex = room[a].size();
    int j = n_vertex-1;
    int i;
    bool result = false;

    for(i = 0 ; i < n_vertex ; i++)
    {
        if((p.y < room[a][i].y && p.y >= room[a][j].y)||(p.y >= room[a][i].y && p.y < room[a][j].y))
        {
            if(room[a][i].x == room[a][j].x)
            {
                if(room[a][i].x < p.x) result = !result;
            }
            else if(room[a][i].x + (room[a][j].x - room[a][i].x)/(room[a][j].y - room[a][i].y)*(p.y - room[a][i].y) < p.x) result = !result;
        }
        j = i;
    }

    return result;
}

int main()
{
    int n_case;
    int n_compartment;
    int n_vertex;
    int n_test;
    int i = 1;

    cin >> n_case;
    while(i <= n_case)
    {
        cin >> n_compartment;
        int j = 1;
        room.clear();
        while(j <= n_compartment)
        {
            cin >> n_vertex;
            int k = 1;
            compartment.clear();
            Point input;
            while(k <= n_vertex)
            {
                cin >> input.x >> input.y;
                compartment.push_back(input);
                k++;
            }
            room.push_back(compartment);
            j++;
        }

        cin >> n_test;
        cout << "Case " << i << ':' << endl;
        int l = 1;
        Point start,target;
        while(l <= n_test)
        {
            int count = 0;
            int a,b;
            cin >> start.x >> start.y >> target.x >> target.y;
            for(a = 0 ; a < n_compartment ; a++)
            {
                if(insideCompartment(a,start)^insideCompartment(a,target)) count++;
            }
            cout << count << endl;
            l++;
        }

        i++;
    }

    return 0;
}
