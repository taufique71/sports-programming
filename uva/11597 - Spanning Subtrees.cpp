#include <iostream>
using namespace std;

int main()
{
    int n_case = 1;
    int vertice;
    while(cin >> vertice)
    {
        if(vertice == 0) break;
        printf("Case %d: %d\n",n_case,vertice/2);
        n_case++;
    }
    return 0;
}
