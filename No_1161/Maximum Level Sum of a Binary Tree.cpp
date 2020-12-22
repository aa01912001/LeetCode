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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        int level = 1, max = root->val, ret = 1;
        q.push(root);
        while(!q.empty()) { // DFS
            int size = q.size(); // the number of nodes of this level 
            int sum = 0;
            for(int i=1; i<=size; i++) {
                sum += q.front()->val; // calculate level sum
                if(q.front()->left) {
                    q.push(q.front()->left);
                }
                
                if(q.front()->right) {
                    q.push(q.front()->right);
                }
                q.pop();
            }
            ret = max >= sum ? ret : level; // update maximum level
            max = max > sum ? max : sum; // update maximum level sum
            level++;
        }
        
        return ret;
    }
    
};