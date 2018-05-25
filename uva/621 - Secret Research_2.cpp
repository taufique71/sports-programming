#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n_case;
    char input[100000];
    scanf("%d",&n_case);

    while(n_case--)
    {
        scanf("%s",input);

        int len = strlen(input);

        if((strcmp(input,"1") == 0)||(strcmp(input,"4") == 0)||(strcmp(input,"78") == 0)) cout << '+' << endl;
        else if(input[len-1] == '5' && input[len-2] == '3') cout << '-' << endl;
        else if(input[0] == '9' && input[len-1] == '4') cout << '*' << endl;
        else if(input[0] == '1' && input[1] == '9' && input[2] == '0') cout << '?' << endl;
    }

    return 0;
}
