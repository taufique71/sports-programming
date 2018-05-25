#include <iostream>
#include <cstdio>
#define MAX 100000
using namespace std;

int maximum(int a,int b)
{
    if(a > b) return a;
    else return b;
}

int X[MAX],P[MAX],M[MAX],S[MAX];
int L;

int main()
{
    int i,j,n;
    int u,v;
    L = 0;
    for(i = 0 ; scanf("%d",&X[i]) != EOF ; i++)
    {
        if(L == 0)
        {
            M[L] = i;
            P[i] = -1;
            L++;
        }
        else
        {
            if(X[i] > X[M[L-1]])
            {
                P[i] = M[L-1];
                M[L] = i;
                L++;
            }

            else
            {
                for(u=0,v=L-1;u<v;)
                {
                    int m = (u+v)/2;
                    if(X[i] > X[M[m]]) u = m+1;
                    else v = m;
                }
                u--;

                if(u < 0)
                {
                    P[i] = -1;
                    M[0] = i;
                    L = maximum(L,1);
                }
                else
                {
                    P[i] = M[u];
                    M[u+1] = i;
                    L = maximum(L,u+1);
                }
            }
        }
        //cout << "L : " << L << endl;
    }

    cout << L << endl << '-' << endl;
    j = M[L-1];
    int s = 0;
    while(P[j] != -1)
    {
        S[s++] = X[j];
        j = P[j];
    }
    S[s] = X[j];
    while(s>=0)
    {
        cout << S[s] << endl;
        s--;
    }
    return 0;
}
