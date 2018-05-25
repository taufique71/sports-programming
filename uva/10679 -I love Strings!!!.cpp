#include <iostream>
#include <cstring>
#define MAX_REF 100001
#define MAX_CHECK 1001
#define ZERO 0
using namespace std;

int t[MAX_CHECK];

void table_build(char w[])
{
    int pos = 0;
    int cnd = 0;
    int len = strlen(w);

    t[pos++] = -1;
    t[pos++] = 0;

    while(pos < len)
    {
        if(w[cnd] == w[pos-1])
        {
            cnd++;
            t[pos] = cnd;
            pos++;
        }
        else if(cnd > 0)
        {
            cnd = t[cnd];
        }
        else
        {
            t[pos] = 0;
            pos++;
        }
    }
}

int kmp_search(char original[], char child[])
{
    int len_or = strlen(original);
    int len_ch = strlen(child);
    int m = 0;
    int i = 0;

    //cout << "Original : " << original << endl;
    //cout << "Child : " << child << endl;

    while((m+i) < len_or)
    {
        //cout << "checking " << original[m+i] << " with " << child[i];
        if(original[m+i] == child[i])
        {
            //cout << " yes " << " m is : " << m << " i is : " << i << endl;
            if(i == len_ch - 1) return 1;
            i++;
        }
        else
        {
            //cout << " no " << " m is : " << m << " i is : " << i << endl;
            m = m + i - t[i];
            if(t[i] > -1) i = t[i];
            else i = 0;
        }
    }

    return 0;
}

int substring(char original[],char child[])
{
    int len_child = strlen(child);
    if(len_child > 1)
    {
        table_build(child);
        //for(int i = 0 ; i < len_child ; i++) cout << t[i] << ' ';
        //cout << endl;
        return kmp_search(original,child);
    }
    else
    {
        for(int i = 0 ; original[i] ; i++)
        {
            if(child[0] == original[i]) return 1;
        }
        return 0;
    }
}

int main()
{
    int n_case;
    int n_check;
    char reference[MAX_REF];
    char check_str[MAX_CHECK];
    char gar[5];
    cin >> n_case;
    gets(gar);

    while(n_case--)
    {
        gets(reference);
        cin >> n_check;
        gets(gar);
        while(n_check--)
        {
            gets(check_str);
            if(substring(reference,check_str)) cout << 'y' << endl;
            else cout << 'n' << endl;
        }
    }

    return 0;
}
