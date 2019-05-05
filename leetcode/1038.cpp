/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        func(root, 0);
        return root;
    }
    
    int func(TreeNode* root, int sum){
        if(root == NULL) return sum;
        int sr = func(root->right, sum);
        root->val = sr + root->val;
        int sl = func(root->left, root->val);
        return sl;
    }
};
