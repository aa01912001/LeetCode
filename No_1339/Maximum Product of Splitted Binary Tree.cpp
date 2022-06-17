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
    long long int total = 0;
    long long int ret = 0;
public:
    int maxProduct(TreeNode* root) {
        total = TreeSum(root);
        solve(root);
        return ret % (int)(1e9+7);
    }
    
    long long int TreeSum(TreeNode* root) {
        if(root == nullptr) return 0;
        return root->val + TreeSum(root->left) + TreeSum(root->right);
    }
    
    long long int solve(TreeNode* root) {
        if(root == nullptr) return 0;
        long long int left = solve(root->left);
        long long int right = solve(root->right);
        if(left != 0) {
            ret = max(ret, left*(total-left));
        }
        if(right != 0) {
            ret = max(ret, right*(total-right));
        }
        
        return left + right + root->val;
    }
};