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
    int ret = INT_MAX;
public:
    int minDiffInBST(TreeNode* root) {
        if(root == nullptr) return 0;
        if(root->left == nullptr && root->right == nullptr) return 0;
        int leftMax = findLeftMax(root->left);
        int rightMin = findRightMin(root->right);
        ret = min(ret, min(root->val-leftMax, rightMin-root->val));
        minDiffInBST(root->left);
        minDiffInBST(root->right);
        return ret;
    }
    
    int findLeftMax(TreeNode* root) {
        if(root == nullptr) return -1000000;
        if(root->right == nullptr) return root->val;
        return findLeftMax(root->right);
    }
    
    int findRightMin(TreeNode* root) {
        if(root == nullptr) return 1000000;
        if(root->left == nullptr) return root->val;
        return findRightMin(root->left);
    }
};