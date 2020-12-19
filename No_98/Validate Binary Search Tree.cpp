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
    vector<int> sort;
    
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        inOrder(root);
        for(int i=1; i<sort.size(); i++) { // determine whether sort is strictly increasing sequence order
            if(sort[i] <= sort[i-1]) return false;
        }
        
        return true;
    }  
    
    void inOrder(TreeNode* root) { // search the tree with inorder
        if(root == NULL) return;
        inOrder(root->left);
        sort.push_back(root->val);
        inOrder(root->right);
        return;
    }
};