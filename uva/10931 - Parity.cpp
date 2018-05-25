#include <iostream>
#include <cstring>
using namespace std;

int c;
char bin[50];

void calculate(int n)
{
    int i = 0,j;
    c = 0;

    if(n%2) c++;
    bin[i++] = (n%2)+48;
    n /= 2;

    while(n)
    {
        if(n%2) c++;
        bin[i++] = (n%2)+48;
        n /= 2;
    }
    bin[i] = '\0';

    for(i = 0,j = strlen(bin)-1 ; i < j ; i++,j-- )
    {
        char temp = bin[i];
        bin[i] = bin[j];
        bin[j] = temp;
    }
}

int main()
{
    int n;

    while(cin >> n)
    {
        if(n == 0) break;
        else
        {
            calculate(n);
            cout << "The parity of " << bin << " is " << c << " (mod 2)." << endl;
        }
    }
    return 0;
}
