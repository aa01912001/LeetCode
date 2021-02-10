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
    int xorTable[10] = {0, 1, 2, 4, 8, 16, 32, 64, 128, 256}; // stands for every bit from 1 ~ 9

public:
    int pseudoPalindromicPaths (TreeNode* root) {
        int tmp_xor = 0;
        int ret = 0;
        DFS(root, tmp_xor, ret);
        
        return ret;
    }
    
    void DFS(TreeNode* root, int tmp_xor, int& ret) {
        if(root->left == nullptr && root->right == nullptr) { // if root == leaf
            tmp_xor = xorTable[root->val] ^ tmp_xor;
            if(tmp_xor == 0  || log2(tmp_xor) == int(log2(tmp_xor))) ret++;
            return;
        }
        
        tmp_xor = tmp_xor ^ xorTable[root->val];
        
        if(root->left != nullptr) DFS(root->left, tmp_xor, ret); // DFS for left child
        if(root->right != nullptr) DFS(root->right, tmp_xor, ret); // DFS for right child
        
        return;
    }
};