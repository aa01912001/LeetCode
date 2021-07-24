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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ret;
        while(!q.empty()) {
            int size = q.size();
            vector<int> level(size, 0);
            for(int i=0; i<size; i++) {
                TreeNode* t = q.front();
                q.pop();
                level[i] = t->val;
                if(t->left != nullptr) {
                    q.push(t->left);
                }
                
                if(t->right != nullptr) {
                    q.push(t->right);
                }
            }
            
            ret.push_back(level);
        }
        
        return ret;
    }
};