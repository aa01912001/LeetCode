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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr) return new TreeNode(val);
        TreeNode* t = root;
        while(1) {
            if(val < t->val) {  // if the val of node greater than val 
                if(t->left == nullptr) { // if no left child
                    t->left = new TreeNode(val);    
                    break;
                }
                t = t->left;
            } else { // if the val of node less than val
                if(t->right == nullptr) { // if no right child
                    t->right = new TreeNode(val);    
                    break;
                }
                t = t->right;
            }
        }
        
        return root;
    }
};