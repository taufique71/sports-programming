#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<long long int> age;

int compare(long long int a, long long int b)
{
    return(a < b);
}

int main()
{
    long long int n_people;
    long long int a;
    while(cin >> n_people)
    {
        if(n_people == 0) break;

        age.clear();

        while(n_people--)
        {
            cin >> a;
            age.push_back(a);
        }
        sort(age.begin(),age.end(),compare);

        n_people = age.size();
        long long int i = 0;
        while(n_people--)
        {
            cout << age[i];
            if(n_people) cout << ' ';
            i++;
        }
        cout << endl;
    }
}
