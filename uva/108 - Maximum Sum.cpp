#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    long arr[100][100];
    long sum[100][100];
    long n,i,j,sum2,max=0,k,l;
    cin>>n;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==0&j==0) sum[i][j]=arr[i][j];
            else if(i==0&&j!=0) sum[i][j]=sum[i][j-1]+arr[i][j];
            else if(i!=0&&j==0) sum[i][j]=sum[i-1][j]+arr[i][j];
            else sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+arr[i][j];
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=i;k<n;k++)
            {
                for(l=j;l<n;l++)
                {
                    if(i==0&j==0) sum2=sum[k][l];
                    else if(i==0&&j!=0) sum2=sum[k][l]-sum[k][j-1];
                    else if(i!=0&&j==0) sum2=sum[k][l]-sum[i-1][l];
                    else sum2=sum[k][l]-sum[k][j-1]-sum[i-1][l]+sum[i-1][j-1];
                    if(sum2>max) max=sum2;
                }
            }
        }
    }
    cout<<max<<'\n';

    return 0;
}
