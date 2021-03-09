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
    int maxAncestorDiff(TreeNode* root) {
        int ret = 0;
        DFS(root, ret, root->val, root->val);
        return ret;
    }
    
    void DFS(TreeNode* root, int &ret, int minValue, int maxValue) {
        if(root == nullptr) return;
        
        minValue = min(minValue, root->val);
        maxValue = max(maxValue, root->val);
        
        ret = max(ret, abs(maxValue-minValue));
        
        DFS(root->left, ret, minValue, maxValue);
        DFS(root->right, ret, minValue, maxValue);
        
        return;
    }
    
};