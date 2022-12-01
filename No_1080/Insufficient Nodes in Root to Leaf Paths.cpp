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
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        return DFS(root, 0, limit) ? nullptr : root;
    }
    
    bool DFS(TreeNode* root, int sum, int& limit) {
        if(root->left == nullptr && root->right == nullptr) {
            if(sum+root->val < limit)
                return true;
            return false;
        }
        
        int left = true, right = true;
        if(root->left != nullptr)
            left = DFS(root->left, sum + root->val, limit);
        if(root->right != nullptr)
            right = DFS(root->right, sum + root->val, limit);

        if(left)
            root->left = nullptr;
        if(right)
            root->right = nullptr;
        
        return left && right;
    }
};