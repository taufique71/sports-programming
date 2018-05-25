#include <iostream>
using namespace std;

int main()
{
    unsigned char c;
    char line[10050];
    char gar[5];
    int n_case;
    int n_cost;
    int n_line;
    int cost;
    unsigned long long int n_cents;
    cin >> n_case;

    while(n_case--)
    {
        cin >> n_cost;
        int map[1260] = {0};
        n_cents = 0;
        while(n_cost--)
        {
            cin >> c >> cost;
            int i = (int)c;
            map[i] = cost;
        }
        cin >> n_line;
        gets(gar);
        while(n_line--)
        {
            gets(line);
            for(int i = 0 ; line[i] ; i++) n_cents += map[(int)line[i]];
        }

        unsigned long long int final_dollar = n_cents / 100;
        unsigned long long int final_cent = n_cents % 100;

        printf("%lld.%02lld",final_dollar,final_cent);
        cout << '$' << endl;

    }

    return 0;
}
