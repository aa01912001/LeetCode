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
    unordered_map<int,int> hmap;
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        DFS(root);
        vector<int> ret;
        int maxF = -1;
        for(auto &t : hmap) {
            maxF = max(maxF, t.second);
        }
        
        for(auto &t : hmap) {
            if(t.second == maxF) ret.push_back(t.first);
        }
        
        return ret;
    }
    
    int DFS(TreeNode* root) {
        if(root == nullptr) return 0;
        
        int treeSum = 0;
        treeSum = DFS(root->left) + DFS(root->right) + root->val;
        
        hmap[treeSum]++;
        
        return treeSum;
    }
};