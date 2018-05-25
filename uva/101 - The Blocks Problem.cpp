#include <iostream>
#include <cstring>

using namespace std;

int cola,colb,posa,posb;
int N;

char m[]="move";
char p[]="pile";
char on[]="onto";
char ov[]="over";
char q[]="quit";


/**************************             Class Declaration           ********************************/

class stack
{
    int arr[30];
    int top;

public:
    stack()
    {
        top=-1;
    }

    void push(int n)
    {
        top++;
        arr[top]=n;
    }

    int pop()
    {
        int n;
        n=arr[top];
        top--;
        return n;
    }

    int size()
    {
        return (top+1);
    }

    void init(int n)
    {
        top=0;
        arr[top]=n;
    }

    int search(int n)
    {
        int i;
        for(i=0;i<=top;i++)
        {
            if(arr[i]==n) return i;
        }
        return -1;
    }

    void show()
    {
        if(size()<=0) return;
        int i=0;
        for(i=0;i<=top;i++)
        {
            cout<<' '<<arr[i];
        }
    }

}stk[30],tempa,tempb;


/****************************         Functions for Searching       ***************************/


void search_a(int a)
{
    int i=0,pos;

    for(i=0;i<N;i++)
    {
        pos=stk[i].search(a);
        if(pos>-1)
        {
            cola=i;
            posa=pos;
            break;
        }
    }
}

void search_b(int b)
{
    int i=0,pos;

    for(i=0;i<N;i++)
    {
        pos=stk[i].search(b);
        if(pos>-1)
        {
            colb=i;
            posb=pos;
            break;
        }
    }
}

/********************************        Functions for Moves            ******************************/

void put_init(int a)
{
    stack s;

    for(;stk[a].size()>0;) s.push(stk[a].pop());
    stk[a].push(a);
    for(;s.size()>0;) stk[a].push(s.pop());
}


void move_onto(int a,int b)
{
    int temp_b,i=0;

    search_a(a);
    search_b(b);

    if(cola==colb) return;

    for(i=stk[cola].size()-1;i>posa;i--) put_init(stk[cola].pop());
    temp_b=stk[cola].pop();

    search_b(b);

    for(i=stk[colb].size()-1;i>posb;i--) put_init(stk[colb].pop());
    stk[colb].push(temp_b);
}

void move_over(int a,int b)
{
    int temp_b,i=0;

    search_a(a);
    search_b(b);

    if(cola==colb) return;

    for(i=stk[cola].size()-1;i>posa;i--) put_init(stk[cola].pop());
    temp_b=stk[cola].pop();

    stk[colb].push(temp_b);
}

void pile_onto(int a,int b)
{
    int i;

    search_a(a);
    search_b(b);

    if(cola==colb) return;

    for(i=stk[cola].size()-1;i>=posa;i--) tempa.push(stk[cola].pop());
    search_b(b);
    for(i=stk[colb].size()-1;i>posb;i--) put_init(stk[colb].pop());
    for(;tempa.size()>0;) stk[colb].push(tempa.pop());
}

void pile_over(int a,int b)
{
    int i;

    search_a(a);
    search_b(b);

    if(cola==colb) return;

    for(i=stk[cola].size()-1;i>=posa;i--) tempa.push(stk[cola].pop());
    for(;tempa.size()>0;) stk[colb].push(tempa.pop());

}

/**********************************       Main Function        *********************************/

int main()
{
    int i=0;

    int a,b;
    char com1[5],com2[5];

    cin>>N;

    while(i<N)
    {
        stk[i].init(i);
        i++;
    }

    while(cin>>com1)
    {
        if(!strcmp(com1,q)) break;
        cin>>a>>com2>>b;

        if(!strcmp(com1,m))
        {
            if(!strcmp(com2,on)) move_onto(a,b);
            else move_over(a,b);
        }

        else
        {
            if(!strcmp(com2,on)) pile_onto(a,b);
            else pile_over(a,b);
        }
    }

    for(i=0;i<N;i++)
    {
        cout<<i<<':';
        stk[i].show();
        cout<<endl;
    }

    return 0;
}
