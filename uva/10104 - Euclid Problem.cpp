#include <iostream>
using namespace std;

int main()
{
    int a,b,temp;
    int x,last_x,y,last_y,original_b,original_a;
    int q;

    while(cin >> a >> b)
    {
        x = 0;
        last_x = 1;
        y = 1;
        last_y = 0;

        original_a = a;
        original_b = b;

        while(b != 0)
        {
            q = a / b;
            temp = a;
            a = b;
            b = temp % b;

            temp = x;
            x = last_x - temp*q;
            last_x = temp;

            temp = y;
            y = last_y - temp*q;
            last_y = temp;
        }

        a = original_a;
        b = original_b;

        cout << last_x << ' ' << last_y << ' ' << abs(((last_x*a)+(last_y*b))) << endl;
    }
}
