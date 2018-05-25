#include <iostream>
#include <queue>

#define ZERO 0
#define MAX 2510
using namespace std;

int main()
{
    int n_case;
    int n_person;
    int n_friend;
    int frnd;
    int unique_source;
    int i,j;
    int boom_count;
    int boom_day;
    int max_day;
    //cout << 't';
    cin >> n_person;
    //int connection[ZERO+n_person][ZERO+n_person];
    vector<int> temp(ZERO+n_person,0);
    vector< vector<int> > connection;
    for(i = 0 ; i < ZERO+n_person ; i++) connection.push_back(temp);

    i = 0;
    while(i < n_person)
    {
        cin >> n_friend;
        while(n_friend--)
        {
            cin >> frnd;
            connection[i][frnd] = 1;
        }
        i++;
    }

    cin >> n_case;
    while(n_case--)
    {
        cin >> unique_source;

        int track[ZERO+n_person];
        int check_list[ZERO+n_person];
        for(i = 0 ; i < n_person ; i++)
        {
            track[i] = 0;
            check_list[i] = 1;
        }

        queue<int> q;
        q.push(unique_source);
        check_list[unique_source] = 0;

        max_day = 0;

        while(q.size() > 0)
        {
            int index = q.front();
            q.pop();

            for(i = 0 ; i < n_person ; i++)
            {
                if((connection[index][i] == 1) && check_list[i])
                {
                    check_list[i] = 0;
                    track[i] = track[index] + 1;
                    q.push(i);
                }
            }
            max_day++;
        }

        boom_count = 0;
        boom_day = 0;
        int count;

        for(i = 1 ; i <= max_day ; i++)
        {
            count = 0;
            for(j = 0 ; j < n_person ; j++) if(track[j] == i) count++;
            if(count > boom_count)
            {
                boom_count = count;
                boom_day = i;
            }
        }

        cout << boom_count;
        if(boom_count > 0) cout << ' ' << boom_day;
        cout << endl;
    }

    return 0;
}
