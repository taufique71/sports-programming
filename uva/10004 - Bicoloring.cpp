#include <iostream>

#define SIZE 200

using namespace std;

int white = 1;
int red = 2;
int green = 3;
int colorless = 0;
int rit = 1;
int wrong = 0;
int checked = 1;
int unchecked = 0;

int graph[200][200];


/*********************          Node Class Declaration             ***********************/

class Node
{
public:
    int color ;
    int condition ;

}node[SIZE];


/****************            Queue Class Declaration             ****************/


class Queue
{
    int arr[SIZE];
    int front;
    int rear;

public:
    Queue()
    {
        front = 0;
        rear = 0;
    }

    int size()
    {
        return ((SIZE - front + rear) % SIZE) ;
    }

    void enqueue(int n)
    {
        arr[rear] = n;
        rear = (rear + 1) % SIZE;
    }

    int dequeue()
    {
        int n;
        n = arr[front];
        front = (front + 1) % SIZE;
        return n;
    }
};


/***********************           Miscelenious Functions           ***********************/


void init()
{
    for(int i=0;i<200;i++)
    {
        for(int j=0;j<200;j++) graph[i][j]=0;
        node[i].color = colorless;
        node[i].condition = unchecked;
    }
}

int color_node(int i,int j)
{
    //cout<<"Inside color_node"<<endl;
    /****************cout<<"Colouring node "<<j<<" with reference to "<<i<<endl;****************/
    if(node[j].color == white)
    {
        if(node[i].color == red) node[j].color = green;
        else node[j].color = red;
    }

    else
    {
        switch(node[i].color)
        {
            case 2:
                if(node[j].color == red) return wrong;
                break;

            case 3:
                if(node[j].color == green) return wrong;
                break;
        }
    }

    //cout<<"Going out of color_node"<<endl;
    return rit;
}

int bfs(int i,int n)
{
    //cout<<"Inside bfs"<<endl;
    int m;
    Queue q;

    node[i].color = red;
    q.enqueue(i);

    while(q.size() > 0)
    {
        m = q.dequeue();

        for(i = 0;i < n;i++)
        {
            if((graph[m][i] == 1)||(graph[i][m] == 1))
            {
                if(color_node(m,i) == wrong) return wrong;
                if(node[i].condition == unchecked)
                {
                    q.enqueue(i);
                    node[i].condition = checked;
                }
            }
        }
        /*****************cout<<"Queue size is "<<q.size()<<endl;****************/
        //cout<<endl<<endl<<endl<<endl;
    }

    //cout<<"Going out of bfs"<<endl;
    return rit;
}

int traverse (int n)
{
    //cout<<"Inside traverse"<<endl;
    int i;

    for(i = 0; i<n ;i++)
    {
        if(node[i].color == white)
        {
            if(!bfs(i,n)) return wrong;
        }
    }

    //cout<<"Going out of traverse"<<endl;
    return rit;
}


/**********************           Main Function            *********************/


int main()
{
    int n,e;
    int node1,node2;

    while(cin >> n)
    {
        if(!n) break;
        init();
        cin >> e;

        while(e--)
        {
            cin>>node1>>node2;
            graph[node1][node2] = 1;
            node[node1].color = white;
            node[node2].color = white;
        }

        if(traverse(n)) cout<<"BICOLORABLE."<<endl;
        else cout<<"NOT BICOLORABLE."<<endl;
    }
    return 0;
}
