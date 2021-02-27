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
    int goodNodes(TreeNode* root) {
        int ret = 0;
        DFS(root, INT_MIN, ret);
        
        return ret;
    }
    
    void DFS(TreeNode* root, int pathMax, int &ret) {
        if(root == nullptr) return;
        
        if(root->val >= pathMax) {
            pathMax = root->val;
            ret++;
        }
        
        DFS(root->left, pathMax, ret);
        DFS(root->right, pathMax, ret);
        
        return;
    }
};