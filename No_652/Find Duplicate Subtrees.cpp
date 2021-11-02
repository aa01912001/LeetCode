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
    vector<TreeNode*> ret;
    unordered_map<string, int> hmap;
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfsPath(root, "");
        return ret;
    }
    
    string dfsPath(TreeNode* root, string path) {
        if(root == nullptr) return "";
        path += to_string(root->val) + "/" + dfsPath(root->left, path) + "\\" + dfsPath(root->right, path);
        if(++hmap[path] == 2) { // duplicate subtree
            ret.push_back(root);
        }
        
        return path;
    }
};