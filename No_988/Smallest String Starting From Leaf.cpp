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
    string smallestFromLeaf(TreeNode* root) {
        if(root == nullptr) return "";
        vector<string> allPath = DFS(root);
        string ret = allPath[0];
        for(int i=1; i<allPath.size(); i++) {
            if(allPath[i] < ret) ret = allPath[i];
        }
        return ret;
    }
    
    vector<string> DFS(TreeNode *root) {
        if(root == nullptr) return {};
        if(root->left == nullptr && root->right == nullptr) {
            string s = "";
            s = s + (char)(root->val+'a');
            return {s};
        }
        
        vector<string> l = DFS(root->left);
        vector<string> r = DFS(root->right);
        vector<string> possiblePath;
        for(int i=0; i<l.size(); i++) {
            possiblePath.push_back(l[i]+(char)(root->val+'a'));
        }
        for(int i=0; i<r.size(); i++) {
            possiblePath.push_back(r[i]+(char)(root->val+'a'));
        }
        
        return possiblePath;
        
        
    }
};