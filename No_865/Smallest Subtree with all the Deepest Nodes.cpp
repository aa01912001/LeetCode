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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int leftHeight = findHeight(root->left);
        int rightHeight = findHeight(root->right);
        if(leftHeight == rightHeight) {
            return root;
        } else if(leftHeight > rightHeight) {
            return subtreeWithAllDeepest(root->left);
        }
        return subtreeWithAllDeepest(root->right);
    }
    
    int findHeight(TreeNode *root) {
        if(root == nullptr) return 0;
        return max(findHeight(root->left), findHeight(root->right)) + 1;
    }
    
   
};