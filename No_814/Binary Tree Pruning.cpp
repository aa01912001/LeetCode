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
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(prune(root)) return nullptr;
        return root; 
    }
    
    bool prune(TreeNode* root) {
        if(root == nullptr) return true;
        bool l = prune(root->left);
        bool r = prune(root->right);
        
        if(l) root->left = nullptr;
        if(r) root->right = nullptr;
        
        return l && r && !root->val;
        
    }
};