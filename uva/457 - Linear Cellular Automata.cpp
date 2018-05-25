#include <iostream>
using namespace std;

int input[10];
char str[] = " .xW";

int find(char c);
char correspond(int n);

int main()
{
    int n;
    cin >> n;

    while(n--)
    {
        cin >> input[0] >> input[1] >> input[2] >> input[3] >> input[4] >> input[5] >> input[6] >> input[7] >> input[8] >> input[9];
        char dish[41] = "                   .                    ";
        int count = 50;
        while(count--)
        {
            puts(dish);
            char temp[41];
            strcpy(temp,dish);
            for(int i = 0 ; i < 40 ; i++)
            {
                if(i == 0)
                {
                    int c = 0 + find(temp[i]) + find(temp[i + 1]);
                    dish[i] = correspond(c);
                }

                else if(i == 39)
                {
                    int c = 0 + find(temp[i]) + find(temp[i - 1]);
                    dish[i] = correspond(c);
                }

                else
                {
                    int c = find(temp[i - 1]) + find(temp[i]) + find(temp[i + 1]);
                    dish[i] = correspond(c);
                }
            }
        }
        if(n) cout << endl;
    }
}

int find(char c)
{
    for(int i = 0 ; i < 4 ; i++)
    {
        if(c == str[i]) return i;
    }
}

char correspond(int n)
{
    return (str[input[n]]);
}
