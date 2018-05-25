#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    char arr[129],c;
    int i;
    arr['1']='`';
    arr['2']='1';
    arr['3']='2';
    arr['4']='3';
    arr['5']='4';
    arr['6']='5';
    arr['7']='6';
    arr['8']='7';
    arr['9']='8';
    arr['0']='9';
    arr['-']='0';
    arr['=']='-';
    arr['\b']='=';
    arr['W']='Q';
    arr['E']='W';
    arr['R']='E';
    arr['T']='R';
    arr['Y']='T';
    arr['U']='Y';
    arr['I']='U';
    arr['O']='I';
    arr['P']='O';
    arr['[']='P';
    arr[']']='[';
    arr['\\']=']';
    arr['S']='A';
    arr['D']='S';
    arr['F']='D';
    arr['G']='F';
    arr['H']='G';
    arr['J']='H';
    arr['K']='J';
    arr['L']='K';
    arr[';']='L';
    arr['\'']=';';
    arr['X']='Z';
    arr['C']='X';
    arr['V']='C';
    arr['B']='V';
    arr['N']='B';
    arr['M']='N';
    arr[',']='M';
    arr['.']=',';
    arr['/']='.';
    arr[' ']=' ';
    while((c=getchar())!=EOF)
    {
        if(c=='\n') cout<<'\n';
        else putchar(arr[c]);
    }
    return 0;
}
