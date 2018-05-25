#include <iostream>
#include <cstring>

#define MAX 2600

using namespace std;

char track[1001][MAX];

char* addition(char num1[] , char num2[])
{
    char* res = new char[MAX];
    char* temp = new char[MAX];
    char* big = new char[MAX];
    char* small = new char[MAX];

    int len_1 = strlen(num1);
    int len_2 = strlen(num2);
    int len_b;
    int len_s;

    if(len_1 >= len_2)
    {
        strcpy(big , num1);
        len_b = len_1;
        strcpy(small , num2);
        len_s = len_2;
    }
    else
    {
        strcpy(small , num1);
        len_b = len_2;
        strcpy(big , num2);
        len_s = len_1;
    }

    int car = 0;
    int i,j,k;
    int flag = 0;

    temp[MAX - 1] = '\0';

    for(i = len_s - 1 , j = len_b - 1 , k = MAX - 2 ; i >= 0 ; i--,j--,k--)
    {
        temp[k] = ((small[i] - 48 + big[j] - 48 + car) % 10) + 48;
        car = ((small[i] - 48 + big[j] - 48 + car) / 10);
    }

    while(j >= 0)
    {
        temp[k] = ((big[j] - 48 + car) % 10) + 48;
        car = ((big[j] - 48 + car) / 10);
        j--;
        k--;
    }

    while(k >= 0)
    {
        temp[k] = (car % 10) + 48;
        car = (car / 10);
        k--;
    }

    return temp;
}

char* multiply_by_digit(char num[] , char digit)
{
    int i = 0;
    int j;
    int car = 0;
    int l = strlen(num);
    int flag = 0;

    char* temp = new char[l + 2];
    char* res = new char[l + 2];
    temp[l + 1] = '\0';

    for(i = l - 1, j = l ; i >= 0 ; i-- , j--)
    {
        temp[j] = (((num[i] - 48) * (digit - 48) + car) % 10) + 48;
        car = (((num[i] - 48) * (digit - 48) + car) / 10);
    }

    while(j >= 0)
    {
        temp[j] = (car % 10) + 48;
        car = (car / 10);
        j--;
    }

    return temp;
}

char* multiply(char num1[] , char num2[])
{
    int len_1 = strlen(num1);
    int len_2 = strlen(num2);
    int i,j;
    int count = 0;

    char* res = new char[MAX];
    char* temp = new char[MAX];

    strcpy(res , "0");

    for(j = len_2 - 1; j >= 0 ; j--)
    {
        strcpy(temp , multiply_by_digit(num1 , num2[j]));

        i = 0;
        while(i < count)
        {
            strcat(temp , "0");
            i++;
        }

        strcpy(res , addition(res , temp));

        count++;
    }

    i = 0;
    while(res[i] == '0') i++;

    j = 0;
    while(res[i] != '\0')
    {
        temp[j] = res[i];
        i++;
        j++;
    }
    temp[j] = '\0';

    return temp;
}

void generate()
{
    char temp[MAX];
    int i;

    for(i = 0 ; i < 1001 ; i++)
    {
        if(i == 0) strcpy(track[i] , "1");
        else
        {
            sprintf(temp , "%d" , i);
            strcpy(track[i] , multiply(track[i - 1] , temp));
        }
    }

    return;
}

int main()
{
    int n;

    generate();

    while(cin >> n) cout << n << '!' << endl << track[n] << endl;

    return 0;
}
