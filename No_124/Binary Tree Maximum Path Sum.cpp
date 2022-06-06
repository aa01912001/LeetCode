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
    int ret = INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        DFS(root);
        return ret;
    }
    
    int DFS(TreeNode *root) {
        if(root == nullptr) return 0;
        int leftMaxPath = DFS(root->left) + root->val;
        int rightMaxPath = DFS(root->right) + root->val;
        int tmp = max(root->val, max(leftMaxPath, rightMaxPath));
        ret = max(ret, max(tmp, leftMaxPath+rightMaxPath-root->val));
        return tmp;
    }
};