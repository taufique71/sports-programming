#include <iostream>
#include <cstring>
using namespace std;

char fibonacci[500][110];

char* add(char a[],char b[])
{
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

void count_fib()
{
    int i = 0;
    strcpy(fibonacci[i++],"1");
    strcpy(fibonacci[i++],"1");
    while(i < 500)
    {
        strcpy(fibonacci[i],add(fibonacci[i-1],fibonacci[i-2]));
        i++;
    }
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

int main()
{
    count_fib();
    char a[110],b[110];
    while(cin >> a >> b)
    {
        if(strcmp(a,"0")==0 && strcmp(b,"0")==0) break;
        int i = 0;
        int count = 0;
        for(i = 1 ; i < 500 ; i++)
        {
            if((is_greater(fibonacci[i],a) >= 0)&&(is_lesser(fibonacci[i],b) >= 0)) count++;
        }
        cout << count << endl;
    }
    return 0;
}
