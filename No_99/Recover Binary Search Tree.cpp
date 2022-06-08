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
    TreeNode* pre = nullptr;
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
public:
    void recoverTree(TreeNode* root) {
        inorder(root);
        // swap the value of two nodes
        first->val = first->val ^ second->val;
        second->val = first->val ^ second->val;
        first->val = first->val ^ second->val;
    }
    
    void inorder(TreeNode* root) {
        if(root == nullptr) return;
        inorder(root->left);
        if(!first && pre && root->val < pre->val) first = pre;
        if(first && root->val < pre->val) second = root;
        pre = root;
        inorder(root->right);
        return;
    }
};