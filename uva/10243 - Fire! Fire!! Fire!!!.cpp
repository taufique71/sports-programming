#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX 1010
using namespace std;

class node
{
public:
    int value;
    node* next;
};

node list[MAX];
bool cover[MAX];
bool color[MAX];
int order[MAX];
int parent[MAX];
int nv,cnt;
int t;

void insert(int i,int n)
{
    node* p = new node;
    p->value = n;
    p->next = list[i].next;
    list[i].next = p;
}

void show_list()
{
    for(int i = 0 ; i < nv ; i++)
    {
        cout << i << " : ";
        node* p = &list[i];
        while(p->next != NULL)
        {
            cout << p->next->value << ' ';
            p = p->next;
        }
        cout << endl;
    }
}

void dfs(int i)
{
    order[t++] = i;
    color[i] = false;
    //cout << "visiting : " << i << endl;
    node* p = &list[i];
    while(p->next != NULL)
    {
        if(color[p->next->value] == true)
        {
            parent[p->next->value] = i;
            dfs(p->next->value);
        }
        p = p->next;
    }
}

void minimum_vertex_cover()
{
    int i,j,k;
    for(k = t-1 ; k >= 0 ; k--)
    {
        i = order[k];
        if(!cover[i] && parent[i] != -1)
        {
            if(!cover[parent[i]])
            {
                cover[parent[i]] = true;
                cnt++;
                //cout << "increasing " << i << endl;
            }
        }
        else
        {
            if(parent[i] == -1 && list[i].next == NULL)
            {
                cover[i] = true;
                cnt++;
            }
        }
    }
}

int main()
{
    int i,j;
    int na;
    int a,b;
    while(scanf("%d",&nv) != EOF)
    {
        if(nv == 0) break;
        memset(color,true,sizeof(color));
        memset(cover,false,sizeof(cover));
        memset(parent,-1,sizeof(parent));
        memset(order,0,sizeof(order));
        t = 0;
        cnt = 0;
        for(i = 0 ; i < nv ; i++)
        {
            list[i].value = i;
            list[i].next = NULL;

            scanf("%d",&na);

            for(j = 0; j < na ; j++)
            {
                scanf("%d",&a);
                a--;
                insert(i,a);
            }
        }
        //show_list();
        dfs(0);
        //cout << "order: ";for(i = 0 ; i < t ; i++) cout << order[i] << ' ';
        //cout << endl;
        minimum_vertex_cover();
        cout << cnt << endl;
    }
}
