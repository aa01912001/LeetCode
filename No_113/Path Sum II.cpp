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
    vector<vector<int>> ret;
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return {};
        vector<int> p;
        DFS(root, targetSum, p);
        
        return ret;
    }
    
    void DFS(TreeNode* root, int remaining, vector<int>& path) {
        if (root == nullptr) return;
        
        remaining -= root->val;
        path.push_back(root->val);
        if (remaining == 0 && root->left == nullptr && root->right == nullptr) {
            ret.push_back(path);
        } else {
            DFS(root->left, remaining, path);
            DFS(root->right, remaining, path);
        }
        
        path.pop_back();
        
        return;
    }
};