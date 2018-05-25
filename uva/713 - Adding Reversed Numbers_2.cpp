#include <iostream>
#include <cstring>
#include <cstdlib>

#define MAX 250

using namespace std;

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

    temp[k] = (car % 10) + 48;
    car = (car / 10);

    while((temp[k] == '0') && (temp[k] != '\0')) k++;

    if(temp[k] == '\0')
    {
        strcpy(res , "0");
        return res;
    }

    i = 0;
    while(temp[k] != '\0')
    {
        res[i] = temp[k];
        k++;
        i++;
    }

    res[i] = '\0';

    return res;
}

char* reverse(char str[])
{
    int i;
    int j;
    char temp;

    for(i = 0,j = strlen(str) - 1; i < j ; i++,j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    return str;
}

void print_output(char res[])
{
    int i = 0;

    if(strcmp(res , "0") == 0)
    {
        cout << res << endl;
        return;
    }

    while(res[i] == '0') i++;

    while(res[i] != '\0')
    {
        cout << res[i];
        i++;
    }
    cout << endl;

    return;
}

int main()
{
    char num1[MAX] , num2[MAX] , res[MAX];
    int n1 , n2 , result , kase;

    cin >> kase;
    while(kase--)
    {
        cin >> num1 >> num2 ;
        strcpy(num1 , reverse(num1));
        strcpy(num2 , reverse(num2));

        strcpy(res , addition(num1 , num2));
        strcpy(res , reverse(res));

        print_output(res);
    }
    return 0;
}
