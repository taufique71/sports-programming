#include <iostream>
#include <cmath>

#define SIZE 10000

using namespace std;

class list
{
    int arr[SIZE];
    int siz;

public:
    list()
    {
        siz = 0;
    }

    int median()
    {
        int mid = (siz / 2) + 1;

        if(siz % 2) return arr[mid - 1];
        else return ((arr[mid - 1] + arr[mid - 2]) / 2);
    }

    void insert(int n)
    {
        int i , j;
        for(i = 0; i < siz ; i++)
        {
            if(arr[i] > n)   break;
        }

        for(j = siz; j > i; j--)
        {
            arr[j] = arr[j-1];
        }

        arr[i] = n;

        siz++;
    }
};


/************************        Main Function       ************************/


int main()
{
    int n;
    list l;

    while(cin >> n)
    {
        if(n < 0) break;
        l.insert(n);
        cout << l.median() <<endl;
    }
    return 0;
}
