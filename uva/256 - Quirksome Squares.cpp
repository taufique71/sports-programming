#include <iostream>
using namespace std;

char two[] = "00\n01\n81\n";
char four[] = "0000\n0001\n2025\n3025\n9801\n";
char six[] = "000000\n000001\n088209\n494209\n998001\n";
char eight[] = "00000000\n00000001\n04941729\n07441984\n24502500\n25502500\n52881984\n60481729\n99980001\n";

int main()
{
    int n;

    while(cin >> n)
    {
        if(n == 2) cout << two;
        else if(n == 4) cout << four;
        else if(n == 6) cout << six;
        else if(n == 8) cout << eight;
    }

    return 0;
}
