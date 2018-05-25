#include <iostream>

#define MAX_COM 101
#define MAX_GRID 51

using namespace std;

char north = 'N';
char east = 'E';
char south = 'S';
char west = 'W';

int white = 0;
int red = 1;

int max_x , max_y;

int grid[MAX_GRID][MAX_GRID];

class Robot
{
public:
    char dir;
    int x;
    int y;
    char cond[10];

    Robot()
    {
        x = 0;
        y = 0;
        dir = north;
        strcpy(cond , "EXISTS");
    }

    void reRobot()
    {
        x = 0;
        y = 0;
        dir = north;
        strcpy(cond , "EXISTS");
    }
}robot;

int canBeInside()
{
    switch(robot.dir)
    {
        case 'N':
            if((robot.y+1)<=max_y) return 1;
            else return 0;

        case 'E':
            if((robot.x+1)<=max_x) return 1;
            else return 0;

        case 'W':
            if((robot.x-1)>=0) return 1;
            else return 0;

        case 'S':
            if((robot.y-1)>=0) return 1;
            else return 0;
    }
}

int main()
{
    int i , j;
    char flush[5];
    char command[MAX_COM];

    cin >> max_x >> max_y;

    while(cin >> robot.x >> robot.y >> robot.dir)
    {
        gets(flush);
        gets(command);

        for(i = 0 ; (command[i] != '\0')&&(strcmp(robot.cond,"LOST")) ; i++)
        {
            switch(command[i])
            {
                case 'R':
                    switch(robot.dir)
                    {
                        case 'N':
                            robot.dir = east;
                            break;
                        case 'E':
                            robot.dir = south;
                            break;
                        case 'S':
                            robot.dir = west;
                            break;
                        case 'W':
                            robot.dir = north;
                            break;
                    }
                    break;

                case 'F':
                    switch(robot.dir)
                    {
                        case 'N':
                            if(canBeInside())
                            {
                                robot.y += 1;
                            }
                            else
                            {
                                if(grid[robot.x][robot.y] == white )
                                {
                                    grid[robot.x][robot.y] = red;
                                    strcpy(robot.cond , "LOST");
                                }
                            }
                            break;

                        case 'E':
                            if(canBeInside())
                            {
                                robot.x += 1;
                            }
                            else
                            {
                                if(grid[robot.x][robot.y] == white )
                                {
                                    grid[robot.x][robot.y] = red;
                                    strcpy(robot.cond , "LOST");
                                }
                            }
                            break;

                        case 'S':
                            if(canBeInside())
                            {
                                robot.y -= 1;
                            }
                            else
                            {
                                if(grid[robot.x][robot.y] == white )
                                {
                                    grid[robot.x][robot.y] = red;
                                    strcpy(robot.cond , "LOST");
                                }
                            }
                            break;

                        case 'W':
                            if(canBeInside())
                            {
                                robot.x -= 1;
                            }
                            else
                            {
                                if(grid[robot.x][robot.y] == white )
                                {
                                    grid[robot.x][robot.y] = red;
                                    strcpy(robot.cond , "LOST");
                                }
                            }
                            break;
                    }
                    break;

                case 'L':
                    switch(robot.dir)
                    {
                        case 'N':
                            robot.dir = west;
                            break;
                        case 'E':
                            robot.dir = north;
                            break;
                        case 'S':
                            robot.dir = east;
                            break;
                        case 'W':
                            robot.dir = south;
                            break;
                    }
                    break;
            }
        }
        cout << robot.x << ' ' << robot.y << ' ' << robot.dir;
        if(!strcmp(robot.cond , "LOST")) cout << ' ' << robot.cond;
        cout << endl;
        robot.reRobot();
    }

    return 0;
}
