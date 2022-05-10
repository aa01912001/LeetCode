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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root;
        root = solve(0, preorder.size()-1, 0, inorder.size()-1, preorder, inorder);
        return root;
    }
    
    TreeNode* solve(int preStart, int preEnd, int inStart, int inEnd, vector<int>& preorder, vector<int>& inorder) {
        if(preStart > preEnd) return nullptr;
        
        int v = preorder[preStart];
        TreeNode* n = new TreeNode(v);
        
        int count = 0;
        for(int i=inStart; i<=inEnd; i++) {
            if(inorder[i] == v) break;
            count++;
        }
        
        n->left = solve(preStart+1, preStart+count, inStart, inStart+count-1, preorder, inorder);
        n->right = solve(preStart+count+1, preEnd, inStart+count+1, inEnd, preorder, inorder);
            
        return n;
    }
};