#include <iostream>
using namespace std;

void printBangla(long long int num)
{
    int kuti = 0;
    int lakh = 0;
    int hajar = 0;
    int shata = 0;
    int normal = 0;

    kuti = num / 10000000;
    num = num % 10000000;
    if(kuti > 0) printf(" %d kuti",kuti);
    lakh = num / 100000;
    num = num % 100000;
    if(lakh > 0) printf(" %d lakh",lakh);
    hajar = num / 1000;
    num = num % 1000;
    if(hajar > 0) printf(" %d hajar",hajar);
    shata = num / 100;
    num = num % 100;
    if(shata > 0) printf(" %d shata",shata);
    normal = num;
    if(normal > 0) printf(" %d",normal);
}
int main()
{
    long long int num;
    int kuti;
    int lakh;
    int hajar;
    int shata;
    int normal;
    int n_case = 1;
    int flag = 0;

    while(cin >> num)
    {
        printf("%4d.",n_case);
        flag = 0;

        kuti = 0;
        lakh = 0;
        hajar = 0;
        shata = 0;
        normal = 0;

        kuti = num / 10000000;
        num = num % 10000000;
        if(kuti > 0)
        {
            printBangla(kuti);
            printf(" kuti");
            flag = 1;
        }

        lakh = num / 100000;
        num = num % 100000;
        if(lakh > 0)
        {
            flag = 1;
            printf(" %d lakh",lakh);
        }

        hajar = num / 1000;
        num = num % 1000;
        if(hajar > 0)
        {
            flag = 1;
            printf(" %d hajar",hajar);
        }
        shata = num / 100;
        num = num % 100;
        if(shata > 0)
        {
            flag = 1;
            printf(" %d shata",shata);
        }
        normal = num;
        if(normal > 0 || flag == 0) printf(" %d",normal);

        cout << endl;
        n_case++;
    }
    return 0;
}
