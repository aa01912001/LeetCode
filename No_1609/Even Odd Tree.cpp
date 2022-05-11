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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        
        while(!q.empty()) {
            int n = q.size();
            TreeNode *pre = nullptr;
            while(n) {
                TreeNode *cur = q.front(); q.pop();
                if(pre == nullptr) { // first node
                    if(level%2 == 0 && cur->val%2 == 0) return false;
                    if(level%2 == 1 && cur->val%2 == 1) return false;

                } else {
                    if(level%2 == 0) { // even level
                        if(cur->val%2 == 0 || cur->val <= pre->val) return false;
                    } else { // odd level
                        if(cur->val%2 == 1 || cur->val >= pre->val) return false;
                    }   
                }
                pre = cur;
                if(pre->left != nullptr) q.push(pre->left);
                if(pre->right != nullptr) q.push(pre->right);
                n--;
            }
            level++;
        }
        
        return true;
    }
};