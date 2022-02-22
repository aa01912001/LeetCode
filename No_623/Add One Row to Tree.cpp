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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        depth--;
        while(depth-- != 1) { // BFS until previous level of target  depth
            vector<TreeNode*> next;
            int size = q.size();
            while(size--) {
                if(q.front()->left != nullptr) {
                    next.push_back(q.front()->left);    
                }
                
                if(q.front()->right != nullptr) {
                    next.push_back(q.front()->right);    
                }
                q.pop();
            }
            for(int i=0; i<next.size(); i++) {
                q.push(next[i]);
            }
        }
        
        while(!q.empty()) { // add one row
            TreeNode* t = q.front(); q.pop();
            TreeNode* l = new TreeNode(val);
            l->left = t->left;
            t->left = l;
            TreeNode* r = new TreeNode(val);
            r->right = t->right;
            t->right = r;
        }
        
        return root;
    }
};