#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cctype>
using namespace std;

class team
{
public:
    int rank;
    char name[50];
    int points;
    int games_played;
    int wins;
    int ties;
    int loses;
    int goal_diff;
    int goal_scored;
    int goal_against;

    team()
    {
        rank = 0;
        points = 0;
        games_played = 0;
        wins = 0;
        ties = 0;
        loses = 0;
        goal_diff = 0;
        goal_scored = 0;
        goal_against = 0;
    }
};

int strcomp(char str1[100],char str2[100])
{
    int i;
    char a[100];
    char b[100];
    strcpy(a,str1);
    strcpy(b,str2);
    for(i = 0 ; a[i] ; i++) a[i] = toupper(a[i]);
    for(i = 0 ; b[i] ; i++) b[i] = toupper(b[i]);
    return strcmp(a,b);
}

bool compare(team team1, team team2)
{
    if(team1.points > team2.points) return true;                    //comparing points
    else if(team1.points < team2.points) return false;
    else
    {
        if(team1.wins > team2.wins) return true;
        else if(team1.wins < team2.wins) return false;
        else
        {
            if(team1.goal_diff > team2.goal_diff) return true;
            else if(team1.goal_diff < team2.goal_diff) return false;
            else
            {
                if(team1.goal_scored > team2.goal_scored) return true;
                else if(team1.goal_scored < team2.goal_scored) return false;
                else
                {
                    if(team1.games_played < team2.games_played) return true;
                    else if(team1.games_played > team2.games_played) return false;
                    else
                    {
                        if(strcomp(team1.name,team2.name) < 0) return true;
                        else return false;
                    }
                }
            }
        }
    }
}

int main()
{
    int n_case;
    int n_teams;
    int n_matches;
    int table_size;
    int flag = 0;
    char tournament[150];

    char gar[5];
    char input_team[50];
    char match_result[150];

    team temp;
    char temp_team1[50];
    char temp_team2[50];
    char temp_team1_goals[10];
    char temp_team2_goals[10];
    int team1_goals;
    int team2_goals;
    int team1_index;
    int team2_index;

    int i,j;

    cin >> n_case;
    gets(gar);

    while(n_case--)
    {
        gets(tournament);
        cin >> n_teams;
        gets(gar);

        vector<team> table;
        while(n_teams--)
        {
            gets(input_team);
            strcpy(temp.name,input_team);
            table.push_back(temp);
        }

        cin >> n_matches;
        gets(gar);

        while(n_matches--)
        {
            gets(match_result);

            char* pch;
            pch = strtok(match_result,"#@");
            strcpy(temp_team1,pch);
            pch = strtok(NULL,"#@");
            strcpy(temp_team1_goals,pch);
            pch = strtok(NULL,"#@");
            strcpy(temp_team2_goals,pch);
            pch = strtok(NULL,"#@");
            strcpy(temp_team2,pch);

            team1_goals = atoi(temp_team1_goals);
            team2_goals = atoi(temp_team2_goals);

            table_size = table.size();

            for(i = 0 ; i < table_size ; i++)
            {
                if(strcmp(table[i].name,temp_team1) == 0) team1_index = i;
                else if(strcmp(table[i].name,temp_team2) == 0) team2_index = i;
            }

            table[team1_index].goal_scored += team1_goals;
            table[team2_index].goal_scored += team2_goals;

            table[team1_index].goal_against += team2_goals;
            table[team2_index].goal_against += team1_goals;

            table[team1_index].goal_diff += (team1_goals - team2_goals);
            table[team2_index].goal_diff += (team2_goals - team1_goals);

            table[team1_index].games_played += 1;
            table[team2_index].games_played += 1;

            if(team1_goals > team2_goals)
            {
                table[team1_index].wins += 1;
                table[team2_index].loses += 1;

                table[team1_index].points += 3;
            }
            else if(team1_goals == team2_goals)
            {
                table[team1_index].ties += 1;
                table[team2_index].ties += 1;

                table[team1_index].points += 1;
                table[team2_index].points += 1;
            }
            else if(team1_goals < team2_goals)
            {
                table[team1_index].loses += 1;
                table[team2_index].wins += 1;

                table[team2_index].points += 3;
            }
        }

        table_size = table.size();
        sort(table.begin(),table.end(),compare);

        for(i = 0 ; i < table_size ; i++) table[i].rank = i+1;

        if(flag == 1) cout << endl;
        cout << tournament << endl;
        for(i = 0 ; i < table_size ; i++) printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",table[i].rank,table[i].name,table[i].points,table[i].games_played,table[i].wins,table[i].ties,table[i].loses,table[i].goal_diff,table[i].goal_scored,table[i].goal_against);
        flag = 1;
    }
}
