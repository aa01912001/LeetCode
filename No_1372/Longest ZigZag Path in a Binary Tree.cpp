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
    int longestZigZag(TreeNode* root) {
        return max(DFS(root->left, 1, 0), DFS(root->right, 1, 1));
    }
    
    int DFS(TreeNode* root, int zPathLen, int direction) {
        if(root == nullptr) {
            return zPathLen - 1;
        }
        
        int l, r;
        if(direction == 0) { // previous direction is left
            l = DFS(root->left, 1, 0);
            r = DFS(root->right, zPathLen+1, 1);
        } else { // previous direction is right
            l = DFS(root->left, zPathLen+1, 0);
            r = DFS(root->right, 1, 1);
        }
        
        return max(l, r);
    }
};