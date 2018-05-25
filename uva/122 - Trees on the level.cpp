#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;

const int blank = 200000000;
bool flag = true;
vector<int> result;

class node
{
public:
    int elem;
    node* left;
    node* right;
};

class tree
{
public:
    node* root;

    tree()
    {
        root = NULL;
    }

    void insert(int value,char* place,node*& ptr)
    {
        if(ptr == NULL)
        {
            ptr = new node;
            ptr ->elem = blank;
            ptr ->left = NULL;
            ptr ->right = NULL;
        }

        if(*place == '\0')
        {
            if(ptr->elem != blank) flag = false;
            ptr->elem = value;
        }
        else
        {
            if(*place == 'L') insert(value,place+1,ptr->left);
            else if(*place == 'R') insert(value,place+1,ptr->right);
        }
    }

    void bfs()
    {
        queue<node*> q;
        node* p;
        if(root != NULL) q.push(root);
        while(!q.empty())
        {
            p = q.front();
            q.pop();
            if(p->elem == blank)
            {
                flag = false;
                break;
            }
            //cout << p->elem << ' ';
            result.push_back(p->elem);

            if(p->left != NULL) q.push(p->left);
            if(p->right != NULL) q.push(p->right);
        }
    }
};

class temp_node
{
public:
    int value;
    char path[300];
};

int main()
{
    int n_case = 1;
    int i,j;
    char input[300];
    temp_node temp;
    vector<temp_node> container;

    while(cin >> input)
    {
        if(strlen(input) <= 2)
        {
            tree t = tree();
            j = container.size();
            for(i = 0 ; i < j ; i++) t.insert(container[i].value,container[i].path,t.root);

            result.clear();
            if(flag == true) t.bfs();
            container.clear();

            if(!flag) cout << "not complete" << endl;
            else
            {
                j = result.size()-1;
                for(i = 0 ; i <= j ; i++)
                {
                    cout << result[i];
                    if(i < j) cout << ' ';
                }
                cout << endl;
            }
            flag = true;
        }
        else
        {
            char* tok = strtok(input,"(),");
            temp.value = atoi(tok);
            //cout << temp.value << ' ';
            tok = strtok(NULL,"(),");
            if(tok != NULL)strcpy(temp.path,tok);
            else strcpy(temp.path,"\0");
            //cout << temp.path << endl;
            container.push_back(temp);
        }
    }

    return 0;
}
