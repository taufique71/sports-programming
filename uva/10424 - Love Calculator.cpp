#include <iostream>
using namespace std;

int main()
{
    int arr[256]={0};
    arr['A']=1;
    arr['B']=2;
    arr['C']=3;
    arr['D']=4;
    arr['E']=5;
    arr['F']=6;
    arr['G']=7;
    arr['H']=8;
    arr['I']=9;
    arr['J']=10;
    arr['K']=11;
    arr['L']=12;
    arr['M']=13;
    arr['N']=14;
    arr['O']=15;
    arr['P']=16;
    arr['Q']=17;
    arr['R']=18;
    arr['S']=19;
    arr['T']=20;
    arr['U']=21;
    arr['V']=22;
    arr['W']=23;
    arr['X']=24;
    arr['Y']=25;
    arr['Z']=26;
    arr['a']=1;
    arr['b']=2;
    arr['c']=3;
    arr['d']=4;
    arr['e']=5;
    arr['f']=6;
    arr['g']=7;
    arr['h']=8;
    arr['i']=9;
    arr['j']=10;
    arr['k']=11;
    arr['l']=12;
    arr['m']=13;
    arr['n']=14;
    arr['o']=15;
    arr['p']=16;
    arr['q']=17;
    arr['r']=18;
    arr['s']=19;
    arr['t']=20;
    arr['u']=21;
    arr['v']=22;
    arr['w']=23;
    arr['x']=24;
    arr['y']=25;
    arr['z']=26;
    arr['1']=1;
    arr['2']=2;
    arr['3']=3;
    arr['4']=4;
    arr['5']=5;
    arr['6']=6;
    arr['7']=7;
    arr['8']=8;
    arr['9']=9;
    arr['0']=0;

    char str1[30];
    char str2[30];
    int sum1,sum2;
    float res,temp1,temp2;

    while((gets(str1))&&(gets(str2)))
    {
        res=0;
        do{
            sum1=0;
            for(int i=0;str1[i]!='\0';i++)
            {
                sum1=sum1+arr[str1[i]];
            }
            sprintf(str1,"%d",sum1);
            temp1=sum1;

        }while((sum1/10)>=1);

        do{
            sum2=0;
            for(int i=0;str2[i]!='\0';i++)
            {
                sum2=sum2+arr[str2[i]];
            }
            sprintf(str2,"%d",sum2);
            temp2=sum2;

        }while((sum2/10)>=1);

        if(temp2>=temp1) res=temp1/temp2;
        else res=temp2/temp1;

        printf("%0.2f",100*res);
        cout<<' '<<'%'<<endl;
    }
    return 0;
}
