#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int X1LL,X2LL,X1UR,X2UR,Y1LL,Y2LL,Y1UR,Y2UR;
    int n_case;
    bool flagX,flagY;
    cin >> n_case;
    while(n_case--)
    {
        cin >> X1LL >> Y1LL >> X1UR >> Y1UR;
        cin >> X2LL >> Y2LL >> X2UR >> Y2UR;

        flagX = false;
        flagY = false;

        if(X1LL <= X2LL)
        {
            if(X1UR > X2LL) flagX = true;
        }
        if(X2LL <= X1LL)
        {
            if(X2UR > X1LL) flagX = true;
        }

        if(Y1LL <= Y2LL)
        {
            if(Y1UR > Y2LL) flagY = true;
        }
        if(Y2LL <= Y1LL)
        {
            if(Y2UR > Y1LL) flagY = true;
        }

        if(flagX && flagY)
        {
            int X[4];
            int Y[4];

            X[0] = X1LL;
            X[1] = X2LL;
            X[2] = X1UR;
            X[3] = X2UR;

            Y[0] = Y1LL;
            Y[1] = Y2LL;
            Y[2] = Y1UR;
            Y[3] = Y2UR;

            sort(X,X+4);
            sort(Y,Y+4);

            printf("%d %d %d %d\n",X[1],Y[1],X[2],Y[2]);
        }
        else printf("No Overlap\n");
        if(n_case) cout << endl;
    }
    return 0;
}
