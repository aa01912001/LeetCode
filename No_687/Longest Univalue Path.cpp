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
    int ret = 0;
public:
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0; 
        DFS(root);
        return ret;
    }
    
    int DFS(TreeNode *root) {
        int leftPath = 0;
        int rightPath = 0;
        if(root->left != nullptr) leftPath = DFS(root->left);
        if(root->right != nullptr) rightPath = DFS(root->right);
        
        if(root->left != nullptr && root->val == root->left->val) {
            leftPath += 1;
        } else {
            leftPath = 0;
        } 
        
        if(root->right != nullptr && root->val == root->right->val) {
            rightPath += 1;
            
        } else {
            rightPath = 0;
        }
        
        ret = max(ret, leftPath+rightPath);
        return max(leftPath, rightPath);
    }
};