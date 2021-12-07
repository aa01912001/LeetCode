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
    string tree2str(TreeNode* root) {
       return DFS(root);
    }
    
    string DFS(TreeNode* root) {
        string s = to_string(root->val);
        if(root->left == nullptr && root->right == nullptr) {
            return s;
        }
        if(root->left == nullptr) {
            s += "()";
        } else {
            s += "(" + DFS(root->left) + ")";    
        }
        
        if(root->right == nullptr) {
            s += "";
        } else {
            s += "(" + DFS(root->right) + ")";    
        }
        
        return s;
    }
};