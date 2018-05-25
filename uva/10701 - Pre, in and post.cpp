#include <iostream>
#include <cstring>
#define ZERO 0
using namespace std;

class Node
{
public:
    int key;
    char value;
    Node* left;
    Node* right;

    Node()
    {
        left = right = NULL;
    }
};

class BST
{
public:
    Node* root;

    BST()
    {
        root = NULL;
    }

    void insert(Node*& ptr, Node n)
    {
        if(ptr == NULL)
        {
            Node* p = new Node;
            p->key = n.key;
            p->value = n.value;
            p->left = n.left;
            p->right = n.right;

            ptr = p;
            //ptr = &n;
        }
        else if(n.key < ptr->key) insert(ptr->left,n);
        else if(n.key > ptr->key) insert(ptr->right,n);
    }

    void post_order(Node* ptr)
    {
        if(ptr != NULL)
        {
            post_order(ptr->left);
            post_order(ptr->right);
            cout << ptr->value;
        }
        //else cout << "pointer is null" << endl;
    }
};

void build_tree(char in[],char pre[])
{
    int len = strlen(in);
    Node nodes[ZERO+len];
    int i,j;

    for(i = 0 ; i < len ; i++)
    {
        for(j = 0 ; j < len ; j++)
        {
            if(pre[i] == in[j]) break;
        }
        nodes[i].key = j;
        nodes[i].value = pre[i];
        nodes[i].left = NULL;
        nodes[i].right = NULL;
    }

    BST tree = BST();
    for(i = 0 ; i < len ; i++)
    {
        //cout << nodes[i].value << ' ' << nodes[i].key << "---";
        tree.insert(tree.root,nodes[i]);
    }
    tree.post_order(tree.root);
    cout << endl;
}

int main()
{
    int n_case;
    int n_node;
    char inorder[100];
    char preorder[100];

    cin >> n_case;

    while(n_case--)
    {
        cin >> n_node >> preorder >> inorder;
        build_tree(inorder,preorder);
    }

    return 0;
}
