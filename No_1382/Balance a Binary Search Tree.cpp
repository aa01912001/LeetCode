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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nodes;
        inOrder(root, nodes);
        
        TreeNode* balancedBST = rebuild(0, nodes.size()-1, nodes);
        return balancedBST;
    }
    
    void inOrder(TreeNode* root, vector<int>& nodes) {
        if(root == nullptr) return;
        inOrder(root->left, nodes);
        nodes.push_back(root->val);
        inOrder(root->right, nodes);
        return;
    }
    
    TreeNode* rebuild(int left, int right, vector<int>& nodes) {
        if(right < left) return nullptr;
        int mid = (left+right)/2;
        TreeNode* t = new TreeNode(nodes[mid]);
        t->left = rebuild(left, mid-1, nodes);
        t->right = rebuild(mid+1, right, nodes);
        return t;
    }
};