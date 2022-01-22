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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        deque<TreeNode*> q;
        q.push_back(root);
        int level = 0;
        vector<vector<int>> ret;
        
        while(!q.empty()) {
            int size = q.size();
            vector<int> l;
            while(size--) {
                if(level%2 == 0) {
                    TreeNode* t = q.front();q.pop_front();
                    l.push_back(t->val);
                    if(t->left != nullptr) q.push_back(t->left);
                    if(t->right != nullptr) q.push_back(t->right);
                } else {
                    TreeNode* t = q.back();q.pop_back();
                    l.push_back(t->val);
                    if(t->right != nullptr) q.push_front(t->right);
                    if(t->left != nullptr) q.push_front(t->left);
                }
            }
            level++;
            ret.push_back(l);
        }
        
        return ret;
    }
};