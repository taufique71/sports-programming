#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAX 1000
#define maximum(a,b) a>b?a:b
using namespace std;

int main()
{
    int n_case;
    char in[15];
    scanf("%d",&n_case);
    gets(in);
    gets(in);
    while(n_case--)
    {
        int X[MAX] = {0};
        int P[MAX] = {0};
        int M[MAX] = {0};
        int S[MAX] = {0};
        int i,j,u,v,m,L;
        i = 0;
        L = 0;
        while(gets(in))
        {
            if(strcmp(in,"") == 0) break;
            X[i] = atoi(in);
            if(L == 0)
            {
                P[i] = -1;
                M[L] = i;
                L++;
                //cout << 'a' << endl;
            }
            else
            {
                if(X[i] > X[M[L-1]])
                {
                    P[i] = M[L-1];
                    M[L] = i;
                    L++;
                    //cout << 'b' << endl;
                }
                else
                {
                    for(u = 0,v = L-1 ; u < v ;)
                    {
                        m = (u+v)/2;
                        if(X[i] > X[M[m]]) u = m+1;
                        else v = m;
                    }
                    u--;

                    if(u < 0)
                    {
                        P[i] = -1;
                        if(X[i] < X[M[0]]) M[0] = i;
                    }
                    else
                    {
                        P[i] = M[u];
                        M[u+1] = i;
                        L = maximum(L,u+1);
                        //cout << 'c' << endl;
                    }
                }
            }
            i++;
            //cout << "L : " << L << endl;
        }

        printf("Max hits: %d\n",L);
        i = M[L-1];
        j = 0;
        while(P[i] != -1)
        {
            S[j] = X[i];
            i = P[i];
            j++;
        }
        S[j] = X[i];
        while(j >= 0)
        {
            printf("%d\n",S[j]);
            j--;
        }
        if(n_case) cout << endl;
    }
    return 0;
}
