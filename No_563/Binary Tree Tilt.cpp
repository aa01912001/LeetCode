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
    int findTilt(TreeNode* root) {
        int ret = 0;
        DFS(root, ret);
        return ret;
    }
    
    int DFS(TreeNode* root, int& ret) {
        if(root == nullptr) return 0;
        int left = DFS(root->left, ret);
        int right = DFS(root->right, ret);
        int d = abs(left-right);
        ret += d;
        return left + right + root->val;
    }
};