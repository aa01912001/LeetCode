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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return {};
        stack<vector<int>> s;
        queue<TreeNode*> q;
        vector<vector<int>> ret;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            vector<int> level;
            for(int i=0; i<size; i++) {
                TreeNode* t = q.front(); q.pop();
                if(t->left != nullptr) q.push(t->left);
                if(t->right != nullptr) q.push(t->right);
                level.push_back(t->val);
            }
            s.push(level);
        }
        
        while(!s.empty()) {
            ret.push_back(s.top());
            s.pop();
        }
        
        return ret;
    }
};