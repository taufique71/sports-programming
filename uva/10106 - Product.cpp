#include <iostream>
#include <cstring>

#define MAX 550

using namespace std;

char res[MAX] = "0";

void add(char num[])
{
    int len_res = strlen(res);
    int len_num = strlen(num);

    int i,j,k,car = 0,flag = 0;

    char temp[MAX];

    for(i = len_num - 1,j = len_res - 1,k = MAX - 1; j >= 0 ; i--,j--,k--)
    {
        temp[k] = ((num[i] - 48 + res[j] - 48 + car) % 10) + 48;
        car = ((num[i] - 48 + res[j] - 48 + car) / 10);
    }

    for(;i >= 0; i--,k--)
    {
        temp[k] = ((num[i] - 48 + car) % 10) + 48;
        car = ((num[i] - 48 + car) / 10);
    }

    temp[k] = (car % 10) + 48;
    car = (car / 10);

    while((k < MAX) && (temp[k] == '0')) k++;

    i = 0;

    for(; k < MAX ; k++,i++)
    {
        flag = 1;
        res[i] = temp[k];
    }

    if(flag == 0) res[i++] = '0';
    res[i] = '\0';
}

void multiply(char num1[], char num2[])
{
    int i,j,k;
    int len_num1 = strlen(num1);
    int len_num2 = strlen(num2);
    int count,car;

    char mult[MAX];

    for(i = len_num2 - 1 , count = 0 ; i >= 0 ; i-- , count++)
    {
        car = 0;
        mult[len_num1 + 1] = '\0';

        for(j = len_num1 - 1 ,k = len_num1; j >= 0 ; j--,k--)
        {
            mult[k] = (((num1[j] - 48) * (num2[i] - 48) + car) % 10) + 48;
            car = (((num1[j] - 48) * (num2[i] - 48) + car) / 10);
        }
        mult[k] = car + 48;

        k = 0;
        while(k < count)
        {
            strcat(mult,"0");
            k++;
        }
        add(mult);
    }
}

int main()
{
    char num1[MAX];
    char num2[MAX];

    while(cin >> num1 >> num2)
    {
        strcpy(res,"0");
        multiply(num1,num2);
        cout << res << endl;
    }

    return 0;
}
