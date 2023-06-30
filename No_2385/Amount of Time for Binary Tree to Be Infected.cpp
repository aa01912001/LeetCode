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
    int startDepth = 0;
public:
    int amountOfTime(TreeNode* root, int start) {
        int ret = 0;
        DFS(root, 0, ret, start);
        
        return ret;
    }
    
    pair<int, bool> DFS(TreeNode* root, int depth, int &ret, int start) {
        int maxDepthLeft = 0, maxDepthRight = 0;
        bool hasStartLeft = false, hasStartRight = false;
        
        if (root->left != nullptr) {
            pair<int, bool> p = DFS(root->left, depth+1, ret, start);
            maxDepthLeft = p.first;
            hasStartLeft = p.second;
        }
        
        if (root->right != nullptr) {
            pair<int, bool> p = DFS(root->right, depth+1, ret, start);
            maxDepthRight = p.first;
            hasStartRight = p.second;
        }
        
        int maxDepth = max(maxDepthLeft, maxDepthRight);
        bool hasStart = false;
        
        if (root->val == start) {
            ret = max(ret, maxDepth);
            startDepth = depth;
            hasStart = true;
        } else if (hasStartLeft) {
            ret = max(ret, startDepth-depth+maxDepthRight);
            hasStart = true;
        } else if (hasStartRight) {
            ret = max(ret, startDepth-depth+maxDepthLeft);
            hasStart = true;
        }
        
        return {maxDepth+1, hasStart};
    }
};