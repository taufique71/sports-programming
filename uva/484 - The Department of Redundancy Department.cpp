#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> num;
    vector<int> count;
    int a,flag;
    while(cin>>a)
    {
        flag=-1;
        for(int i=0;i<num.size();i++)
        {
            if(num[i]==a)
            {
                flag=i;
                break;
            }
            else flag=-1;
        }

        if(flag>=0) count[flag]++;
        else
        {
            num.push_back(a);
            count.push_back(1);
        }
    }
    for(int i=0;i<num.size();i++) cout<<num[i]<<' '<<count[i]<<endl;
    return 0;
}
