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
    int sumRootToLeaf(TreeNode* root) {
        int ret = 0;
        DFS(root, 0, ret);
        return ret;
    }
    
    void DFS(TreeNode* root, int sum, int &ret) {
        if(root == nullptr) return;
        sum <<= 1;
        sum += root->val;
        if(root->left == nullptr && root->right == nullptr) {
            ret += sum;
            return;
        }
        DFS(root->left, sum, ret);
        DFS(root->right, sum, ret);
        return;
    }
};