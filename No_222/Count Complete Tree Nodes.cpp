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
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        int lh = 0, rh = 0;
        TreeNode *l = root->left, *r = root->right;
        while(l != nullptr) { // get left height
            lh++;
            l = l->left;
        }
        while(r != nullptr) { // get right height
            rh++;
            r = r->right;
        }
        
        if(lh == rh) { // it is a full binary tree
            return pow(2, lh+1) - 1;
        }
        
        return countNodes(root->left) + countNodes(root->right) + 1;       
    }
};