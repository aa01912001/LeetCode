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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string ret = "", sPath = "", dPath = "";
        
        DFS(root, startValue, sPath);
        DFS(root, destValue, dPath);
        reverse(sPath.begin(), sPath.end());
        reverse(dPath.begin(), dPath.end());
        
        int i = 0;
        while (sPath[i] == dPath[i]) i++;
        ret = dPath.substr(i, dPath.length()-i);
        while (i < sPath.length()) {
            ret = 'U' + ret;
            i++;
        }
            
        return ret;
    }
    
    bool DFS(TreeNode* root, int value, string &path) {
        if (root->val == value) {
            return true;
        }
        
        if (root->left && DFS(root->left, value, path))
            path.push_back('L');
        
        else if (root->right && DFS(root->right, value, path))
            path.push_back('R');
        
        return path.length() != 0;
    }
};