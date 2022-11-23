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
    TreeNode* recoverFromPreorder(string traversal) {
        return buildTree(0, traversal, 0, traversal.length()-1);
    }
    
    TreeNode* buildTree(int depth, string& traversal, int startIndex, int endIndex) {
        if(startIndex == -1) return nullptr;
        int rootVal = 0;
        int leftTreeStart = -1, rightTreeStart = -1;
        int leftTreeEnd = -1, rightTreeEnd = -1;
        
        // get root val
        int i = startIndex;
        while(i <= endIndex && isdigit(traversal[i])) {
            rootVal *= 10;
            rootVal += traversal[i] - '0';
            i++;
        }
        
        TreeNode* root = new TreeNode(rootVal);
        
        // if root val is postfix
        if(i > endIndex) return root;
        
        // find left subtree start index
        int count = 0;
        for(; i<=endIndex; i++) {
            if(isdigit(traversal[i])) continue;
            count++;
            if(count == depth+1) {
                leftTreeStart = i+1;
                break;
            }       
        }
        
        // find right subtree start and assign end index for left and right subtree 
        count = 0;
        i++;
        for(; i<=endIndex; i++) {
            if(isdigit(traversal[i])) {
                count = 0;
                continue;
            }
            count++;
            if(count == depth+1 && isdigit(traversal[i+1])) {
                rightTreeStart = i+1;
                leftTreeEnd = i - (depth + 1);
                rightTreeEnd = endIndex;
                break;
            }       
        }
        
        // if no right subtree tree 
        if(rightTreeStart == -1) leftTreeEnd = endIndex;
        
        root->left = buildTree(depth+1, traversal, leftTreeStart, leftTreeEnd);
        root->right = buildTree(depth+1, traversal, rightTreeStart, rightTreeEnd);
        
        return root;
    }
};