#include <iostream>
#include <cstring>
using namespace std;

char solutions[100][10];
char result[10];
bool track_row[10];
bool track_column[10];
int r_in;
int s_in;

int check()
{
    int i,j,r1,r2,c1,c2;
    double m;

    j = r_in-1;
    r1 = result[j]-48;
    c1 = j;

    if(r_in > 1)
    {
        for(i = 0 ; i < j ; i++)
        {
            c2 = i;
            r2 = result[i]-48;
            m = ((double)r1-(double)r2)/((double)c1-(double)c2);
            if(m == 1 || m == -1) return 0;
        }
    }

    return r_in+1;
}

void backtrack(int c)
{
    int i,j,r,flag;

    flag = check();
    if(flag == 0) return;
    if(flag == 9)
    {
        result[r_in] = '\0';
        strcpy(solutions[s_in],result);
        s_in++;
        return;
    }

    for(r = 0 ; r < 8 ; r++)
    {
        if(track_row[r])
        {
            result[c] = r+48;
            r_in++;
            track_row[r] = false;
            backtrack(c+1);
            r_in--;
            track_row[r] = true;
        }
    }
}

int main()
{
    int i,j,a;

    for(i = 0 ; i < 10 ; i++)
    {
        track_column[i] = true;
        track_row[i] = true;
    }
    r_in = 0;
    s_in = 0;

    backtrack(0);
    //cout << s_in << endl;

    int init_r,init_c,n_sol;
    int n_case;
    cin >> n_case;

    while(n_case--)
    {
        cin >> init_r >> init_c;
        init_c--;
        init_r--;
        n_sol = 1;

        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");

        for(i = 0 ; i < s_in ; i++)
        {
            if(solutions[i][init_c]-48 == init_r)
            {
                printf("%2d      ",n_sol);
                for(j = 0 ; solutions[i][j] ; j++)
                {
                    if(j > 0) cout << ' ';
                    printf("%d",solutions[i][j]-48 + 1);
                }
                cout << endl;
                n_sol++;
            }
        }
        if(n_case) cout << endl;
    }

    return 0;
}
