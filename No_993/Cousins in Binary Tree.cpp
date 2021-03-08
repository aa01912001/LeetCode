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
    bool isCousins(TreeNode* root, int x, int y) {
        if(root->val == x || root->val == y) return false;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) { // BFS
            bool findX = false, findY = false;
            int size = q.size();
            for(int i=0; i<size; i++) {
                bool findLX = false, findLY = false;
                TreeNode* t = q.front();
                q.pop();
                if(t->left != nullptr) {
                    if(t->left->val == x) {
                        findLX = true;
                        findX = true;
                    }else if(t->left->val == y) {
                        findLY = true;
                        findY = true;
                    }
                    
                    q.push(t->left);
                }
                
                if(t->right != nullptr) {
                    if(t->right->val == x) {
                        findLX = true;
                        findX = true;
                    }else if(t->right->val == y) {
                        findLY = true;
                        findY = true;
                    }
                    q.push(t->right);
                }
                if(findLX && findLY) return false; // same depth but same parent
            }
            
            if(findX && !findY) return false; // different depth
            if(!findX && findY) return false; // different depth
            if(findX && findY) return true; // same depth and different parent
        }
        
        return false;
    }
};