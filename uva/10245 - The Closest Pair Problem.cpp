#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

#define INF 10000
#define MAX 10001

#define S(x)	(x)*(x)
#define D2(A,B)	(S(A.x-B.x) + S(A.y-B.y))
#define dist(A,B)	sqrt(D2(A,B))
using namespace std;

class point
{
    public:
    double x;
    double y;
};

point Pts[MAX];
point PL[MAX];
point PR[MAX];

bool sortX(point a,point b)
{
    if(a.x <= b.x) return true;
    else return false;
}

bool sortY(point a,point b)
{
    if(a.y <= b.y) return true;
    else return false;
}

double closest_pair(int s,int e)
{
    double d;
    double d2;

    int n = e-s+1;
    if(n == 1) return INF;
    else if(n == 2) return dist(Pts[s],Pts[e]);
    else if(n == 3)
    {
        d = dist(Pts[s],Pts[s+1]);
        d2 = dist(Pts[s],Pts[e]);
        if(d2 < d) d = d2;
        d2 = dist(Pts[s+1],Pts[e]);
        if(d2 < d) d = d2;

        return d;
    }

    int m = (s+e)/2;
    d = closest_pair(s,m);
    d2 = closest_pair(m+1,e);
    if(d2 < d) d = d2;

    int nl,nr;
    int i,j;

    for(i = m,nl = 0 ; i >= s ; i--)
    {
        if(Pts[m].x - Pts[i].x > d) break;
        PL[nl++] = Pts[i];
    }
    sort(PL,PL+nl,sortY);

    for(i = m+1,nr = 0 ; i <= e ; i++)
    {
        if(Pts[i].x - Pts[m].x > d) break;
        PR[nr++] = Pts[i];
    }
    sort(PR,PR+nr,sortY);

    for(i = 0 ; i < nl ; i++)
    {
        for(j = 0 ; j < nr ; j++)
        {
            if(PR[j].y - PL[i].y > d) break;
             d2 = dist(PR[j],PL[i]);
             if(d2 < d) d = d2;
        }
    }
    return d;
}

int main()
{
    int np;
    int i,j,k;
    while(cin >> np)
    {
        if(np == 0) break;
        for(i = 0 ; i < np ; i++) scanf("%lf %lf",&Pts[i].x,&Pts[i].y);

        if(np == 1)
        {
            cout << "INFINITY" << endl;
            continue;
        }

        sort(Pts,Pts+np,sortX);

        double d = closest_pair(0,np-1);
        char buffer[100];
        sprintf(buffer,"%0.4lf",d);
        sscanf(buffer,"%lf",&d);

        if(d < INF) printf("%0.4lf\n",d);
        else printf("INFINITY\n");
    }
    return 0;
}
