#include <iostream>
#include <vector>
using namespace std;

int tape_length;
int n_tracks;
int sum;
int unused;
int temp_sum;
vector<int> input;
vector<int> result;
vector<int> temp_result;

void backtrack(int i)
{
    if(tape_length-temp_sum < 0) return;

    if(temp_sum >= sum)
    {
        if(temp_sum == sum)
        {
            if(temp_result.size() > result.size()) result = temp_result;
        }
        else
        {
            result = temp_result;
            sum = temp_sum;
        }
    }

    for(i ; i < n_tracks ; i++)
    {
        temp_result.push_back(input[i]);
        temp_sum += input[i];
        backtrack(i+1);
        temp_sum -= input[i];
        temp_result.pop_back();
    }
    return;
}

int main()
{
    int i,j;
    while(cin >> tape_length >> n_tracks)
    {
        input.clear();
        result.clear();

        sum = 0;
        temp_sum = 0;
        unused = tape_length - sum;

        for(i = 0 ; i < n_tracks ; i++)
        {
            cin >> j;
            input.push_back(j);
        }
        backtrack(0);

        for(i = 0 ; i < result.size() ; i++) cout << result[i] << ' ';
        cout <<"sum:" << sum << endl;
    }
    return 0;
}
