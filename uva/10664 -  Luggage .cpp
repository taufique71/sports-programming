#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>
using namespace std;

int arr[30];

int main()
{
    int t,temp,sum;
    int i,j,k;
    char input[100];
    char garbage;
    cin >> t;
    garbage = getchar();

    while(t--)
    {
        //cout << "t : " << t << endl;
        gets(input);
        stringstream ss(input);
        i = 0;
        sum = 0;
        while(ss >> temp)
        {
            arr[i] = temp;
            sum += arr[i];
            i++;
        }
        k = i;

        if(sum%2) cout << "NO" << endl;
        else
        {
            sum /= 2;
            bool flag = true;
            for(i = 0 ; i < k ; i++)
            {
                if(arr[i] > sum)
                {
                    flag = false;
                    break;
                }
            }
            if(flag == false) cout << "NO" << endl;
            else
            {
                int knap[210] = {0};
                for(i = 0 ; i < k ; i++)
                {
                    for(j = sum ; j >= arr[i] ; j--)
                    {
                        int a = knap[j-arr[i]] + arr[i];
                        if(a > knap[j]) knap[j] = a;
                    }
                }

                if(knap[sum] == sum) cout << "YES" << endl;
                else cout << "NO" << endl;
            }
        }
    }
    return 0;
}
