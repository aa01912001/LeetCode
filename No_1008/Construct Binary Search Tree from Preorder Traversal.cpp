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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.empty()) return nullptr;  

        TreeNode* t = new TreeNode();
        t->val =  preorder[0];

        vector<int> preorderLeft, preorderRight;
        for(int i=1; i<preorder.size(); i++) { // search from 1 to last
            if(preorder[i] < t->val) {
                preorderLeft.push_back(preorder[i]);
            }else {
                preorderRight.push_back(preorder[i]);
            }
        }
        
        t->left = bstFromPreorder(preorderLeft); 
        t->right = bstFromPreorder(preorderRight);
        
        return t;
    }
};