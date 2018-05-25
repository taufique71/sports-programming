#include <iostream>
using namespace std;

#define MAX 2

int main()
{
    long int m=0,n=0,cases=0,i=0,j=0;
    while(cin>>m>>n)
    {
        if(!m&&!n) break;
        int res[m+MAX][n+MAX];
        char min[m+MAX][n+MAX];
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++) res[i][j]=0;
        }
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                cin>>min[i][j];
                if(min[i][j]=='*')
                {
                    res[i-1][j-1]++;
                    res[i-1][j]++;
                    res[i-1][j+1]++;
                    res[i][j-1]++;
                    res[i][j+1]++;
                    res[i+1][j-1]++;
                    res[i+1][j]++;
                    res[i+1][j+1]++;
                }
            }
        }
        if(cases>0) cout<<endl;
        cases++;
        cout<<"Field #"<<cases<<':'<<endl;
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
               if(min[i][j]=='*') cout<<'*';
               else cout<<res[i][j];
               res[i][j]=0;
            }
            cout<<endl;
        }
    }
    return 0;
}
