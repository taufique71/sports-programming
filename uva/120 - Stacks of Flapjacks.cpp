#include <iostream>
#include <cstring>
#include <cstdlib>
#include <deque>
#include <queue>

using namespace std;

deque<int> dq;
deque<int> serial;

/*************       Function for serial-wise insertion       ****************/

void insert(int n)
{
    int i;
    int len = serial.size();
    deque<int>::iterator it = serial.begin();

    for(i = 0; i < len ; i++)
    {
        if(serial.at(i) < n)
        {
            serial.insert((it + i),n);
            len++;
            return;
        }
    }
    serial.push_back(n);
    return;
}

/************       Seperate Function        ***************/

void seperate(char str[])
{
    char *num;
    int n;

    dq.clear();
    serial.clear();

    num = strtok(str," ");

    while(num != NULL)
    {
        n = atoi(num);
        dq.push_front(n);
        insert(n);
        num = strtok(NULL," ");
    }
}

/********************      Function for searching        ********************/

int search(int n)
{
    int i;
    int len = dq.size();

    for(i = len -1; i >= 0 ; i--)
    {
        if(dq[i] == n) return i;
    }
}

/****************    Flip Function    **************/

void flip(int n)
{
    queue<int> temp;

    for(int i = 0; i < n; i++)
    {
        temp.push(dq.back());
        dq.pop_back();
    }

    for(;temp.size() > 0;)
    {
        dq.push_back(temp.front());
        temp.pop();
    }
}

/*****************     Calculate Function      ******************/

void calculate()
{
    int len = dq.size();
    int i;
    int position;

    for(i = 0 ; i < len ; i++)
    {
        if(dq[i] == serial[i]) continue;
        else
        {
            position = search(serial[i]);
            if(position == len - 1)
            {
                cout << (i + 1) << ' ';
                flip(len - i);
            }
            else
            {
                cout << (position + 1) << ' ';
                flip(len - position);
                cout << (i + 1) << ' ';
                flip(len - i);
            }
        }
    }
}

/*******************     Main Function       *******************/

int main()
{
    char str[100];
    while(gets(str))
    {
        puts(str);
        seperate(str);
        calculate();
        cout<< 0 <<endl;
    }
    return 0;
}
