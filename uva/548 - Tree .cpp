#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

const int blank = 2000000000;

class node
{
public:
    int value;
    int key;
    bool flag;
    long long int sum;
    node* left;
    node* right;
};

class binary_search_tree
{
public:
    node* root;
    node* result;
    node* result_field[5000];
    int field_index;

    binary_search_tree()
    {
        root = NULL;
        result = new node;
        result->flag = false;
        field_index = 0;
    }

    node* insert(node* ptr,node n,int carry)
    {
        if(ptr == NULL)
        {
            ptr = new node;
            ptr->flag = false;
            ptr->value = n.value;
            ptr->sum = carry+(ptr->value);
            //cout << carry << ' ' << ptr->value << ' ' << ptr->sum << endl;
            ptr->key = n.key;
            ptr->left = NULL;
            ptr->right = NULL;

            if(result->flag == false)
            {
                result = ptr;
                result->flag = true;
            }
            //cout << "staying here" << '-' << ptr->value << endl;

            if(ptr->sum < result->sum)
            {
                //cout << "putting new result" << '-';
                if(result->left == NULL && result->right == NULL)
                {
                    result_field[field_index] = new node;
                    result_field[field_index++] = result;
                }
                ptr->flag = true;
                result->flag = false;
                result = ptr;
                //cout << result->sum << endl;
            }
            else if(ptr->sum == result->sum && ptr->value < result->value)
            {
                //cout << "putting new result" << '-';
                if(result->left == NULL && result->right == NULL)
                {
                    result_field[field_index] = new node;
                    result_field[field_index++] = result;
                }
                ptr->flag = true;
                result->flag = false;
                result = ptr;
                //cout << result->sum << endl;
            }
        }
        else
        {
            if(result == ptr)
            {
                //cout << "cleaning" << '-' << result->sum << endl;
                result->flag = false;
            }
            if(n.key <= ptr->key)
            {
                //cout << "going left" << '-' << ptr->value << endl;
                ptr->left = insert(ptr->left,n,ptr->sum);
            }
            else
            {
                //cout << "going right" << '-' << ptr->value << endl;
                ptr->right = insert(ptr->right,n,ptr->sum);
            }
        }

        return ptr;
    }

    node* finalize()
    {
        node* t = new node;
        if(field_index == 0) return result;
        else
        {
            /*cout << "total " << field_index << endl;
            for(int i = 0 ; i < field_index ; i++) cout << result_field[i]->value << ' ';
            cout << endl;*/
            t = result;
            for(int i = 0 ; i < field_index ; i++)
            {
                if(t->sum > result_field[i]->sum) t = result_field[i];
                else if(t->sum == result_field[i]->sum && t->value > result_field[i]->value) t = result_field[i];
            }
        }
        return t;
    }
};

int main()
{
    char in_input[100000];
    char post_input[100000];

    int inorder[10010];
    int postorder[10010];

    int in_index;
    int post_index;

    char *temp = new char[10];
    char gar[10];
    int i,j;
    node t;

    while(gets(in_input))
    {
        gets(post_input);

        in_index = 0;
        temp = strtok(in_input," ");
        while(temp != NULL)
        {
            inorder[in_index] = atoi(temp);
            in_index++;
            temp = strtok(NULL," ");
        }

        post_index = 0;
        temp = strtok(post_input," ");
        while(temp != NULL)
        {
            postorder[post_index] = atoi(temp);
            post_index++;
            temp = strtok(NULL," ");
        }

        binary_search_tree bst = binary_search_tree();

        for(i = post_index-1 ; i >= 0 ; i--)
        {
            for(j = 0 ; j <= in_index-1 ; j++)
            {
                if(postorder[i] == inorder[j]) break;
            }
            t.key = j;
            t.value = postorder[i];
            bst.root = bst.insert(bst.root,t,0);
        }
        cout << bst.finalize()->value << endl;
    }
    return 0;
}

