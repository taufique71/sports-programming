#include <iostream>
#include <cstring>

#define MAX 110

using namespace std;

char fibonacci[110][30];

char* add(char s1[], char s2[])
{
    char *a = new char[110];
    char *b = new char[110];

    if(strlen(s1) >= strlen(s2))
    {
        strcpy(a,s1);
        strcpy(b,s2);
    }
    else
    {
        strcpy(b,s1);
        strcpy(a,s2);
    }

    char* temp = new char[110];
    char* result = new char[110];
    int len_a = strlen(a) - 1;
    int len_b = strlen(b) - 1;
    temp[109] = '\0';
    int len_temp = 108;
    int carry = 0;
    int i;
    while(len_b >= 0)
    {
        temp[len_temp] = (b[len_b]-48 + a[len_a]-48 + carry) % 10 + 48;
        carry = (b[len_b]-48 + a[len_a]-48 + carry) / 10;
        len_temp--;
        len_a--;
        len_b--;
    }

    while(len_a >= 0)
    {
        temp[len_temp] = (a[len_a]-48 + carry) % 10 + 48;
        carry = (a[len_a]-48 + carry) / 10;
        len_temp--;
        len_a--;
    }

    temp[len_temp] = carry % 10 + 48;
    carry = carry / 10;

    while(temp[len_temp] == '0') len_temp++;
    for(i = 0 ; temp[len_temp] ; i++,len_temp++) result[i] = temp[len_temp];
    result[i] = '\0';

    return result;
}

int is_greater(char a[], char b[])
{
    int len_a = strlen(a);
    int len_b = strlen(b);
    if(len_a > len_b) return 1;
    else if(len_a < len_b) return -1;
    else return strcmp(a,b);
}

int is_lesser(char a[], char b[])
{
    int len_a = strlen(a);
    int len_b = strlen(b);
    if(len_a < len_b) return 1;
    else if(len_a > len_b) return -1;
    else return strcmp(b,a);
}

void generateFibonacci()
{
    int i = 0;
    strcpy(fibonacci[i++],"1");
    strcpy(fibonacci[i++],"2");
    while(i < 110)
    {
        strcpy(fibonacci[i],add(fibonacci[i-1],fibonacci[i-2]));
        i++;
    }
}

char* subtract(char s1[], char s2[])              // Subtraction(returns just defference not negetive value)
{
    char* a = new char[MAX];
    char* b = new char[MAX];
    char* temp = new char[MAX];
    char* res = new char[MAX];
    int i,j;

    if(is_greater(s1,s2) >= 0)
    {
        strcpy(a,s1);
        for(i = 0 ; a[i] ; i++) b[i] = '0';
        b[i] = '\0';
        i--;
        for(j = strlen(s2) - 1 ; j >= 0 ; j--,i--) b[i] = s2[j];
    }
    else
    {
        strcpy(a,s2);
        for(i = 0 ; a[i] ; i++) b[i] = '0';
        b[i] = '\0';
        i--;
        for(j = strlen(s1) - 1 ; j >= 0 ; j--,i--) b[i] = s1[j];
    }

    int borrow = 0;
    int num1,num2;
    temp[strlen(a)] = '\0';

    for(i = strlen(a) - 1 ; i >= 0 ; i--)
    {
        num2 = b[i] - 48 + borrow;
        num1 = a[i] - 48;
        if(num2 > num1)
        {
            num1 += 10;
            borrow = 1;
        }
        else borrow = 0;

        temp[i] = num1 - num2 + 48;
    }

    i = 0;
    while(temp[i] == '0') i++;
    if(temp[i]) for(j = 0 ; temp[i] ; j++,i++) res[j] = temp[i];
    else res[j++] = '0';
    res[j] = '\0';

    return res;
}

void generateResult(char num[],char* (&res))
{
    if(is_lesser(num,"0") >= 0) return;
    int i = 0;
    while(is_greater(num,fibonacci[i]) >= 0) i++;
    i--;
    res[i] = '1';
    generateResult(subtract(num,fibonacci[i]),res);
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
    generateFibonacci();

    char fibinary_1[110],fibinary_2[110];
    char sum[110];
    char gar[5];
    int i,j;
    int flag = 0;

    while(cin >> fibinary_1 >> fibinary_2)
    {
        int len_1 = strlen(fibinary_1) - 1;
        int len_2 = strlen(fibinary_2) - 1;
        strcpy(sum,"0");

        for(i = len_1 ; i >= 0 ; i--)
        {
            if(fibinary_1[i] == '1') strcpy(sum,add(sum,fibonacci[len_1 - i]));
        }

        for(i = len_2 ; i >= 0 ; i--)
        {
            if(fibinary_2[i] == '1') strcpy(sum,add(sum,fibonacci[len_2 - i]));
        }
        /* Summing ends here */

        char *result = new char[MAX];
        for(i = 0 ; i < MAX ; i++) result[i] = '0';
        result[MAX - 1] = '\0';
        generateResult(sum,result);
        /* Raw result is generated */

        for(i = MAX - 2 ; (result[i] == '0')&&(i > 0) ; i--);
        i++;
        result[i] = '\0';
        /* Result cleaning up finished*/

        reverse(result);
        /* Finalizing result by reversing the string ends here*/

        if(flag) cout << endl;
        cout << result << endl;
        flag = 1;
    }
    return 0;
}
