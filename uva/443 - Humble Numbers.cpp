#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_VALUE 2000000000

using namespace std;

vector<long long int> humble;
int c;

bool search(long long int n)
{
    for(int i = 0 ; i < c ; i++)
    {
        if(humble[i] == n) return true;
    }

    return false;
}

char* stndrdth(int n)
{
    n = n % 100;

    if(n == 11 || n == 12 || n == 13) return ("th");
    else if(n % 10 == 1) return ("st");
    else if(n % 10 == 2) return ("nd");
    else if(n % 10 == 3) return ("rd");
    else return ("th");
}

int main()
{
    int input;
    long long int temp;

    humble.push_back(1);
    c++;

    for(int i = 0; c < 5842 ; i++)
    {
        temp = humble[i] * 2;
        if(temp <= MAX_VALUE)
        {
            if(!search(temp))
            {
                humble.push_back(temp);
                c++;
            }
        }

        temp = humble[i] * 3;
        if(temp <= MAX_VALUE)
        {
            if(!search(temp))
            {
                humble.push_back(temp);
                c++;
            }
        }

        temp = humble[i] * 5;
        if(temp <= MAX_VALUE)
        {
            if(!search(temp))
            {
                humble.push_back(temp);
                c++;
            }
        }

        temp = humble[i] * 7;
        if(temp <= MAX_VALUE)
        {
            if(!search(temp))
            {
                humble.push_back(temp);
                c++;
            }
        }
    }

    sort(humble.begin() , humble.end());

    while(cin >> input)
    {
        if(input == 0) break;
        cout << "The " << input << stndrdth(input) << " humble number is " << humble[input-1] << "." << endl;
    }

    return 0;
}
