#include <iostream>
#include <cstring>
using namespace std;

char input[30][30];

int main()
{
    int n_case = 1;
    int order;
    int i,j,m,n,desired,current,max;
    char temp[30];

    cin >> n_case;
    gets(temp);

    while(n_case)
    {
        gets(temp);
        gets(temp);

        order = strlen(temp);
        strcpy(input[0],temp);

        for(i = 1 ; i < order ; i++) gets(input[i]);

        /*cout << endl;
        for(i = 0 ; i < order ; i++) cout << input[i] << endl;
        cout << endl;*/

        short int sum[order][order];

        for(i = 0 ; i < order ; i++)
        {
            for(j = 0 ; j < order ; j++)
            {
                if(i == 0 && j == 0) sum[i][j] = input[i][j]-48;
                else if(i == 0) sum[i][j] = sum[i][j-1] + input[i][j]-48;
                else if(j == 0) sum[i][j] = sum[i-1][j] + input[i][j]-48;
                else sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + input[i][j]-48;
            }
        }

        /*for(i = 0 ; i < order ; i++)
        {
            for(j = 0 ; j < order ; j++) cout << sum[i][j] << '\t';
            cout << endl;
        }
        cout << endl;*/

        max = 0;
        for(i = 0 ; i < order ; i++)
        {
            for(j = 0 ; j < order ; j++)
            {
                for(m = i ; m < order ; m++)
                {
                    for(n = j ; n < order ; n++)
                    {
                        desired = (m-i+1)*(n-j+1);
                        if(i == 0 && j == 0) current = sum[m][n];
                        else if(i == 0) current = sum[m][n] - sum[m][j-1];
                        else if(j == 0) current = sum[m][n] - sum[i-1][n];
                        else current = sum[m][n] - sum[i-1][n] - sum[m][j-1] + sum[i-1][j-1];

                        if(current == desired)
                        {
                            if(current > max) max = current;
                        }
                    }
                }
            }
        }
        cout << max << endl;
        n_case--;
        if(n_case) cout << endl;
    }
    return 0;
}
