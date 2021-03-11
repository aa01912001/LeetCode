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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ret, ans;
        ret.push_back(root);
        TreeNode** t = &root;
        DFS(t, to_delete, ret);
        
        for(int i=0; i<ret.size(); i++) {
            if(ret[i] != nullptr) {
                if(find(to_delete.begin(), to_delete.end(), ret[i]->val) == to_delete.end()) {
                    ans.push_back(ret[i]);   
                }
            }
        }
        
        return ans;
    }  
    
    void DFS(TreeNode** root, vector<int>& to_delete, vector<TreeNode*>& ret) {
        if(*root == nullptr) return;
        
        if(find(to_delete.begin(), to_delete.end(), (*root)->val) != to_delete.end()) { // if current node is in to_delete, push its left and right into vector
            ret.push_back((*root)->left);
            ret.push_back((*root)->right);
        }
        
        DFS(&((*root)->left), to_delete, ret);
        DFS(&((*root)->right), to_delete, ret);
        if(find(to_delete.begin(), to_delete.end(), (*root)->val) != to_delete.end()) {
            *root = nullptr;
        }
        
        return;
    }
};