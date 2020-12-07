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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        multiset<int> ms;
        inorder(root1, ms);
        inorder(root2, ms);
        vector<int> ret = vector<int>(ms.begin(), ms.end());
        return ret;
    }
    
    void inorder(TreeNode* root, multiset<int>& ms) { // to traverse a tree in inorder way.
        if(root == nullptr) return;
        inorder(root->left, ms);
        ms.insert(root->val);
        inorder(root->right, ms);
        return;
    }
    
};