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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int root = postorder[n-1];
        int index = 0;
        for(; index<n; index++) {
            if(inorder[index] == root) break;
        }
        
        TreeNode *rootNode = new TreeNode(root);
        if(index - 1 >= 0) { 
            vector<int> leftInorder(inorder.begin(), inorder.begin()+index);
            vector<int> leftPostorder(postorder.begin(), postorder.begin()+index);
            rootNode->left = buildTree(leftInorder, leftPostorder);
        }
        
        if(index + 1 < n) {
            vector<int> rightInorder(inorder.begin()+index+1, inorder.end());
            vector<int> rightPostorder(postorder.begin()+index, postorder.end());
            rootNode->right = buildTree(rightInorder, rightPostorder);
        }
        
        return rootNode;
        
    }
};