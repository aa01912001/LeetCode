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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        rightTraverse(root, ret, 1);
        return ret;
    }
    
    void rightTraverse(TreeNode* root, vector<int>& ret, int h) {
        if(root == nullptr) return;
        if(h == ret.size()+1) {
            ret.push_back(root->val);
        }
        
        rightTraverse(root->right, ret, h+1);
        rightTraverse(root->left, ret, h+1);
        
        return;
    }
};