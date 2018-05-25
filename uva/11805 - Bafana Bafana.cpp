#include <iostream>
using namespace std;

int main()
{
    int n_case;
    int case_count = 1;
    int n_players,first_passer,n_passes;
    cin >> n_case;

    while(case_count <= n_case)
    {
        cin >> n_players >> first_passer >> n_passes;
        printf("Case %d: %d\n",case_count,((first_passer-1+n_passes)%n_players)+1);
        case_count++;
    }

    return 0;
}
