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
    int distributeCoins(TreeNode* root) {
        int ret = 0;
        DFS(root, ret);
        return ret;
    }
    
    int DFS(TreeNode* root, int& ret) {
        if(root == nullptr) return 0;
        int l = DFS(root->left, ret); // the needed coins of left subtree
        int r = DFS(root->right, ret); // the needed coins of right subtree
        ret += abs(l) + abs(r); 
        return l + r + root->val - 1;
    }
};