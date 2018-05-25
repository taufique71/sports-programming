#include <iostream>
using namespace std;

int int_map[129];
char char_map[20];

void init()
{
    int_map['0'] = 0;
    int_map['1'] = 1;
    int_map['2'] = 2;
    int_map['3'] = 3;
    int_map['4'] = 4;
    int_map['5'] = 5;
    int_map['6'] = 6;
    int_map['7'] = 7;
    int_map['8'] = 8;
    int_map['9'] = 9;
    int_map['A'] = 10;
    int_map['B'] = 11;
    int_map['C'] = 12;
    int_map['D'] = 13;
    int_map['E'] = 14;
    int_map['F'] = 15;

    char_map[0] = '0';
    char_map[1] = '1';
    char_map[2] = '2';
    char_map[3] = '3';
    char_map[4] = '4';
    char_map[5] = '5';
    char_map[6] = '6';
    char_map[7] = '7';
    char_map[8] = '8';
    char_map[9] = '9';
    char_map[10] = 'A';
    char_map[11] = 'B';
    char_map[12] = 'C';
    char_map[13] = 'D';
    char_map[14] = 'E';
    char_map[15] = 'F';
}

long long int pow(int n,int p)
{
    long long int res = 1;
    int i;
    for(i = 0 ; i < p ; i++) res *= n;

    return res;
}

void reverse(char*(&str))
{
    int len = strlen(str);
    char temp;
    int i,j;

    for(i = 0 ,j = len - 1 ; i < j ; i++,j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main()
{
    init();

    char* input = new char [100];
    char* output = new char[100];
    long long int base_1,base_2;
    long long int decimal_total;
    int i,j;
    int flag;
    int len;

    while(cin >> base_1 >> base_2 >> input)
    {
        j = 0 ;
        i = strlen(input)-1;
        len = strlen(input);
        decimal_total = 0;
        flag = 1;

        while(j < len)
        {
            if(int_map[input[i]] >= base_1)
            {
                flag = 0;
                break;
            }
            decimal_total += int_map[input[i]] * pow(base_1,j);
            i--;
            j++;
        }

        if(flag == 1)
        {
            i = 0;
            do
            {
                output[i++] = char_map[(decimal_total % base_2)];
                decimal_total = decimal_total / base_2;
            }
            while(decimal_total);
            output[i] = '\0';

            reverse(output);
        }

        if(flag == 1) printf("%s base %lld = %s base %lld\n",input,base_1,output,base_2); //cout <<output << ' ' << base_2 << endl;
        else printf("%s is an illegal base %d number\n",input,base_1);
    }
    return 0;
}
