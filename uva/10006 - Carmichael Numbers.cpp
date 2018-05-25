#include <iostream>
using namespace std;

long int carmichael[15] = {561 , 1105 , 1729 , 2465 , 2821 , 6601 , 8911 , 10585 , 15841 , 29341 , 41041 , 46657 , 52633 , 62745 , 63973};

int calc(long int n)
{
    int i;

    for(i = 0; i < 15 ; i++)
    {
        if(n == carmichael[i]) return 1;
    }

    return 0;
}

int main()
{
    long int n;

    while(cin >> n)
    {
        if(n == 0) break;

        if(calc(n)) cout << "The number " << n << " is a Carmichael number." << endl;

        else cout << n << " is normal." <<endl;

    }

    return 0;
}
