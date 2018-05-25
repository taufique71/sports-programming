#include <iostream>
#include <vector>
using namespace std;

int occurance[30];
long long int factorial[21];
vector<char> result;
char input[30];
long long int n;

void fact()
{
    int i;
    factorial[0] = 1;
    for(i = 1; i < 21 ; i++) factorial[i] = factorial[i-1]*i;
}

void init()
{
    int i;
    for(i = 0 ; i < 30 ; i++) occurance[i] = 0;
    for(i = 0 ; input[i] ; i++) occurance[input[i]-'a']++;
    result.clear();
}

void recursion(long long int p)
{
    int i,j;
    long long int div = 1;
    long long int temp = 0;
    long long int current = 0;
    long long int total = 0;

    if(p <= 0)
    {
        for(i = 0 ; i < 26 ; i++)
        {
            while(occurance[i]--)
            {
                result.push_back(i+'a');
            }
        }
        return;
    }

    for(i = 0 ; i < 26 ; i++) total += occurance[i];

    for(i = 0 ; i < 26 ; i++)
    {
        if(occurance[i])
        {
            div = 1;
            for(j = 0 ; j < i ; j++) div *= factorial[occurance[j]];
            div *= factorial[occurance[i]-1];
            for(j = i+1 ; j < 26 ; j++) div *= factorial[occurance[j]];
            temp = factorial[total-1] / div;
            if(current+temp >= p)
            {
                result.push_back(i+'a');
                occurance[i]--;
                recursion(p-current);
                return;
            }
            else current += temp;
        }
    }
}

void output()
{
    int i;
    for(i = 0 ; i < result.size();i++) printf("%c",result[i]);
    cout << endl;
}

int main()
{
    fact();

    int n_case;

    scanf("%d",&n_case);

    while(n_case--)
    {
        scanf("%s %lld",input,&n);
        init();
        recursion(n+1);
        output();
    }

    return 0;
}
