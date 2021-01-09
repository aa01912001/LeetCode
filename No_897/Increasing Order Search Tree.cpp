/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:

public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *t = new TreeNode();
        TreeNode *tmp = t;
        inorder(root, &tmp);
        return t->right;
    }
    
    void inorder(TreeNode* root, TreeNode** tmp) {
        if(root == nullptr) return;
        
        if(root->left == nullptr && root->right == nullptr) {
            (*tmp)->right = root;
            *tmp = root;
            return;
        }
        
        inorder(root->left, tmp);
        
        root->left = nullptr;
        (*tmp)->right = root;
        *tmp = root;
        inorder(root->right, tmp);
        
        return;
    }
};