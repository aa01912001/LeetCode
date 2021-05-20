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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ret;
        DFS(root, 0, ret);
        return ret;
    }
    
    void DFS(TreeNode* root, int depth, vector<int>& ret) {
        if(root == nullptr) return;
        if((int)(ret.size())-1 < depth) {
            ret.push_back(root->val);
        } else {
            ret[depth] = max(ret[depth], root->val);
        }
        
        DFS(root->left, depth+1, ret);
        DFS(root->right, depth+1, ret);
        
        return;
    }
};