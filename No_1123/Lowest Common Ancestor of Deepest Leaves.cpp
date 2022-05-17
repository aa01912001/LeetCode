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
    TreeNode *ret;
    int deepest = -1;
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        postOrder(root, 0);
        return ret;
    }
    
    int postOrder(TreeNode *root, int level) {
        if(root->left == nullptr && root->right == nullptr) {
            if(level > deepest) {
                deepest = level;
                ret = root;
            }
            return level;
        }
        int l_deep, r_deep;
        if(root->left == nullptr) {
            r_deep = postOrder(root->right, level+1);
            if(r_deep > deepest) {
                deepest = r_deep;
                ret = root;
            }
            return r_deep;
        } else if(root->right == nullptr) {
            l_deep = postOrder(root->left, level+1);
            if(l_deep > deepest) {
                deepest = l_deep;
                ret = root;
            }
            return l_deep;
        }
        r_deep = postOrder(root->right, level+1);
        l_deep = postOrder(root->left, level+1);
        if(r_deep == l_deep) {
            if(l_deep >= deepest) {
                deepest = l_deep;
                ret = root;
            }
        }
        return max(l_deep, r_deep);
    }
};