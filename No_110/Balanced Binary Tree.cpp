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
    bool ret = true;
public:
    bool isBalanced(TreeNode* root) {
        DFS(root);
        return ret;
    }
    
    int DFS(TreeNode* root) {
        if (root == nullptr) return 0;
        
        int left = DFS(root->left);
        int right = DFS(root->right);
        
        if (abs(left-right) > 1)
            ret = false;
        
        return max(left, right) + 1;
    }
};