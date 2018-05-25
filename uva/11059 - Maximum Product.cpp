#include <iostream>
#define UNDEF_POS -2147483647
#define UNDEF_NEG +2147483647
using namespace std;

int main()
{
    int n_num;
    int num;
    int n_case = 1;
    while(cin >> n_num)
    {
        long long int max_pos[20] = {0};
        long long int max_neg[20] = {0};

        max_pos[0] = UNDEF_POS;
        max_neg[0] = UNDEF_NEG;

        for(int i = 1 ; i <= n_num ; i++)
        {
            cin >> num;
            if(num > 0)
            {
                if(max_pos[i-1] != UNDEF_POS) max_pos[i] = max_pos[i-1] * num;
                else max_pos[i] = 1 * num;
                if(max_neg[i-1] != UNDEF_NEG) max_neg[i] = max_neg[i-1] * num;
                else max_neg[i] = UNDEF_NEG;
            }
            else if(num < 0)
            {
                if(max_neg[i-1] != UNDEF_NEG) max_pos[i] = max_neg[i-1] * num;
                else max_pos[i] = UNDEF_POS;
                if(max_pos[i-1] != UNDEF_POS) max_neg[i] = max_pos[i-1] * num;
                else max_neg[i] = 1 * num;
            }
            else
            {
                max_pos[i] = UNDEF_POS;
                max_neg[i] = UNDEF_NEG;
            }
        }
        long long int result = 0;
        for(int i = 1 ; i <= n_num ; i++) if(max_pos[i] > result) result = max_pos[i];
        cout << "Case #" << n_case << ": The maximum product is " << result << "." << endl << endl;
        n_case++;
    }
    return 0;
}
