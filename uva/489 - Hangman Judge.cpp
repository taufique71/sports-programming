#include <iostream>
#include <cstring>

#define ZERO 0

using namespace std;

int process(char ans[],char guess[]);

int main()
{
    int round;
    char ans[100];
    char guess[100];

    while(cin >> round)
    {
        if(round < 0) break;

        cin >> ans >> guess;
        cout << "Round " << round << endl;
        if(process(ans,guess) == 1) cout << "You win." << endl;
        else if(process(ans,guess) == 2) cout << "You lose." << endl;
        else if(process(ans,guess) == 3) cout << "You chickened out." << endl;
    }

    return 0;
}

int process(char ans[],char guess[])
{
    int len_ans = strlen(ans);
    int len_guess = strlen(guess);
    int flag,sum;
    int count = 7;

    int bit[ZERO + len_ans];

    for(int i = 0; i < len_ans ; i++)
    {
        bit[i] = 0;
    }

    for(int i = 0; i < len_guess ; i++)
    {
        flag = 0;
        if(count <= 0) break;

        for(int j = 0 ; j < len_ans ; j++)
        {
            if(guess[i] == ans[j])
            {
                bit[j] = 1;
                flag = 1;
            }
        }

        if(flag == 0) count --;
    }

    sum = 0;
    for(int i = 0; i < len_ans ; i++) sum += bit[i];
    if(sum == len_ans) return 1;
    else
    {
        if(count <= 0) return 2;
        else return 3;
    }
}
