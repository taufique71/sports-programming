#include <iostream>
#include <cstring>
using namespace std;

class person
{
public:
    char name[20];
    int toSpend;
    int forNFriends;
    int toGet;

    person()
    {
        strcpy(name , "");
        toSpend = 0;
        forNFriends = 0;
        toGet = 0;
    }
};

int main()
{
    int nMembers;
    int i , j , k , l;
    int flag = 0;
    char temp[20];

    while(cin >> nMembers)
    {
        person group[nMembers + 0];

        if(flag) cout << endl;

        for(i = 0 ; i < nMembers ; i++)
        {
            cin >> group[i].name;
        }

        for(i = 0 ; i < nMembers ; i++)
        {
            cin >> temp;
            for(j = 0 ; j < nMembers ; j++)
            {
                if(strcmp(temp , group[j].name) == 0) break;
            }

            cin >> group[j].toSpend;
            cin >> group[j].forNFriends;

            if(group[j].forNFriends == 0) continue;
            group[j].toGet += (group[j].toSpend % group[j].forNFriends) - group[j].toSpend;

            if(group[j].forNFriends)
            {
                for(k = 0 ; k < group[j].forNFriends ; k++)
                {
                    cin >> temp;
                    for(l = 0 ; l < nMembers ; l++)
                    {
                        if(strcmp(temp,group[l].name) == 0) break;
                    }
                    group[l].toGet += group[j].toSpend / group[j].forNFriends;
                }
            }
        }

        for(i = 0 ; i < nMembers ; i++)
        {
            cout << group[i].name << ' ' << group[i].toGet << endl;
        }
        flag = 1;
    }

    return 0;
}
