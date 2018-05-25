#include <iostream>
#include <vector>

#define MAX_ROW 10
#define MAX_COL 100

using namespace std;

int input[MAX_ROW+2][MAX_COL+2];
int dp[MAX_ROW+2][MAX_COL+2];
int i,j;
int row,col;
int minValue = 2147483647;
int minIndex;

void init()
{
    int a,b;

    for(a = 0 ; a <= MAX_ROW+1 ; a++)
    {
        for(b = 0 ; b <= MAX_COL+1 ; b++)
        {
            input[a][b] = 0;
            dp[a][b] = 0;
        }
    }
}

int min(int a,int b,int c)
{
    if(a <= b)
    {
        if(a <= c) return a;
        else return c;
    }
    else
    {
        if(b <= c) return b;
        else return c;
    }
}

int getIndex()
{
    int ref = min(dp[minIndex-1][j],dp[minIndex][j],dp[minIndex+1][j]);
    int temp1 = 2147483647, temp2 = 2147483647, temp3 = 2147483647;
    int ans;

    if(ref == dp[minIndex-1][j])
    {
        if(minIndex-1 == 0) temp1 = row;
        else temp1 = minIndex-1;
    }
    if(ref == dp[minIndex][j]) temp2 = minIndex;
    if(ref == dp[minIndex+1][j])
    {
        if(minIndex+1 == row+1) temp1 = 1;
        else temp3 = minIndex+1;
    }

    ans = min(temp1,temp2,temp3);

    return ans;
}

int main()
{
    while(cin >> row >> col)
    {
        init();
        for(i = 1 ; i <= row ; i++)
        {
            for(j = 1 ; j <= col ; j++) cin >> input[i][j];
        }

        for(j = col ; j > 0 ; j--)
        {
            dp[0][j+1] = dp[row][j+1];
            dp[row+1][j+1] = dp[1][j+1];

            for(i = 1 ; i <= row ; i++)
            {
                dp[i][j] = input[i][j] + min(dp[i-1][j+1],dp[i][j+1],dp[i+1][j+1]);
            }
        }

        vector<int>outputWay;
        int outputValue = 0;
        minValue = 2147483647;

        for(i = 1 ; i <= row ; i++)
        {
            if(dp[i][1] < minValue)
            {
                minValue = dp[i][1];
                minIndex = i;
            }
        }

        outputValue = minValue;
        outputWay.push_back(minIndex);

        for(j = 2 ; j <= col ; j++)
        {
            minIndex = getIndex();
            outputWay.push_back(minIndex);
        }

        int len = outputWay.size();

        for(i = 0 ; i < len ; i++)
        {
            cout << outputWay[i];
            if(i < len-1) cout << ' ';
        }
        cout << endl << outputValue << endl;
    }

    return 0;
}
