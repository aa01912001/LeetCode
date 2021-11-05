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
    int sumNumbers(TreeNode* root) {
        return DFS(root, 0);
    }
    
    int DFS(TreeNode* root, int accu) {
        if(root->left == nullptr && root->right == nullptr) {
            return accu*10 + root->val;
        }
        
        int leftSum = 0, rightSum = 0;
        if(root->left != nullptr) {
            leftSum = DFS(root->left, accu*10 + root->val);
        }
        
        if(root->right != nullptr) {
            rightSum = DFS(root->right, accu*10 + root->val);
        }
        
        return leftSum + rightSum;
            
    }
};