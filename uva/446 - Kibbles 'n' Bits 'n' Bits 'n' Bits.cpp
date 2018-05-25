#include <iostream>
#include <cstring>
using namespace std;

char bin[71][5];
int deci[71];

void init()
{
    strcpy(bin['0'],"0000");
    strcpy(bin['1'],"0001");
    strcpy(bin['2'],"0010");
    strcpy(bin['3'],"0011");
    strcpy(bin['4'],"0100");
    strcpy(bin['5'],"0101");
    strcpy(bin['6'],"0110");
    strcpy(bin['7'],"0111");
    strcpy(bin['8'],"1000");
    strcpy(bin['9'],"1001");
    strcpy(bin['A'],"1010");
    strcpy(bin['B'],"1011");
    strcpy(bin['C'],"1100");
    strcpy(bin['D'],"1101");
    strcpy(bin['E'],"1110");
    strcpy(bin['F'],"1111");

    deci['0'] = 0;
    deci['1'] = 1;
    deci['2'] = 2;
    deci['3'] = 3;
    deci['4'] = 4;
    deci['5'] = 5;
    deci['6'] = 6;
    deci['7'] = 7;
    deci['8'] = 8;
    deci['9'] = 9;
    deci['A'] = 10;
    deci['B'] = 11;
    deci['C'] = 12;
    deci['D'] = 13;
    deci['E'] = 14;
    deci['F'] = 15;

    return;
}

int power(int n, int p)
{
    int ans = 1;

    for(int i = 1 ; i <= p ; i++) ans *= n;

    return ans;
}

char* conv_bin(char num[])
{
    int l = strlen(num);
    int tar = 3 - l;
    char* res = new char[15];
    strcpy(res , "0");

    while(tar--) strcat(res , bin['0']);

    for(tar = 0 ; num[tar] != '\0' ; tar++) strcat(res , bin[num[tar]]);

    return res;
}

int conv_dec(char num[])
{
    int l = strlen(num);
    int i,j;
    int sum = 0;

    for(i = 0,j = l - 1 ; j >= 0 ; j--,i++) sum += deci[num[j]] * power(16 , i);

    return sum;
}

int main()
{
    int n , ans;
    char oprtr;
    char num1[5];
    char num2[5];

    init();

    cin >> n;

    while(n--)
    {
        cin >> num1 >> oprtr >> num2;

        if(oprtr == '+') ans = conv_dec(num1) + conv_dec(num2);
        else if(oprtr == '-') ans = conv_dec(num1) - conv_dec(num2);

        cout << conv_bin(num1) << ' ' << oprtr << ' ' << conv_bin(num2) << " = " << ans << endl;
    }

    return 0;
}
