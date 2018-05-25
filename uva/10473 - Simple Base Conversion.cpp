#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char input[15];
    long long int num;

    while(cin >> input)
    {
        if(input[0] == '-') break;
        if((strlen(input) >= 3) && (input[0] == '0') && (input[1] == 'x'))
        {
            input[0] = input[1] = ' ';
            sscanf(input , "%llx" , &num);
            printf("%lld\n" , num);
        }
        else
        {
            sscanf(input , "%lld" , &num);
            printf("0x%llX\n",num);
        }
    }

    return 0;
}
