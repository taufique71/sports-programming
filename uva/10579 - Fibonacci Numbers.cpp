#include <iostream>
#include <cstring>

#define MAX 1010
#define MAX_FIB 5000

using namespace std;

char fibonacci[MAX_FIB][MAX];

char* add(char s1[], char s2[])                         // addition
{
    char *a = new char[MAX];
    char *b = new char[MAX];

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

    char* temp = new char[MAX];
    char* result = new char[MAX];
    int len_a = strlen(a) - 1;
    int len_b = strlen(b) - 1;
    temp[MAX - 1] = '\0';
    int len_temp = MAX - 2;
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

void generateFibonacci()
{
    int i = 0;
    strcpy(fibonacci[i++],"1");
    strcpy(fibonacci[i++],"1");
    while(strlen(fibonacci[i-1]) <= 1000)
    {
        strcpy(fibonacci[i],add(fibonacci[i-1],fibonacci[i-2]));
        i++;
    }
}

int main()
{
    generateFibonacci();
    int n;
    while(cin >> n)
    {
        cout << fibonacci[n-1] << endl;
        //cout << strlen(fibonacci[n-1]) << endl;
    }
    return 0;
}
