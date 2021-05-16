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
    int maxSumBST(TreeNode* root) {
        int ret = 0; 
        isBST(root, ret);
        return ret;
    }
    
    pair<bool, vector<int>> isBST(TreeNode* root, int &ret) {
        if(root == nullptr) {
            vector r = {0,0,0};
            return make_pair(true, r);
        }
        
        if(root->left == nullptr && root->right == nullptr) {
            ret = max(ret, root->val);
            vector r = {root->val, root->val, root->val}; 
            return make_pair(true, r);
        }
        
        pair<bool, vector<int>> lTree = isBST(root->left, ret); 
        pair<bool, vector<int>> rTree = isBST(root->right, ret); 

        vector r = {0,0,0}; // {sum of subTree, min value of subTree, max value of subTree}
        if(lTree.first == true && rTree.first == true) { // if both left and right subTree are valid BST
            if(root->right == nullptr && root->val > lTree.second[2]) {
                ret = max(ret, root->val+lTree.second[0]);
                r[0] = root->val+lTree.second[0];
                r[1] = min(lTree.second[1], root->val);
                r[2] = max(lTree.second[2], root->val);
                return make_pair(true, r);
            }
            
            
            if(root->left == nullptr && root->val < rTree.second[1]) {
                ret = max(ret, root->val+rTree.second[0]);
                r[0] = root->val+rTree.second[0];
                r[1] = min(rTree.second[1], root->val);
                r[2] = max(rTree.second[2], root->val);
                return make_pair(true, r);
            }
            
            if(root->val > lTree.second[2] && root->val < rTree.second[1]) {
                ret = max(ret, root->val+lTree.second[0]+rTree.second[0]);
                r[0] = root->val+lTree.second[0]+rTree.second[0];
                r[1] = min(root->val, min(lTree.second[1], rTree.second[1]));
                r[2] = max(root->val, max(lTree.second[2], rTree.second[2]));
                return make_pair(true, r);
            }
            
        }
        
        return make_pair(false, r);
        
    }
};