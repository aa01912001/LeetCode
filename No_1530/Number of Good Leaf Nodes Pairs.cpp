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
    int ret = 0;
public:
    int countPairs(TreeNode* root, int distance) {
        DFS(root, distance);
        return ret;
    }
    
    vector<int> DFS(TreeNode* root, int distance) {
        if(root->left == nullptr && root->right == nullptr) {
            return {1};
        }
        
        vector<int> lLeafDst = {};
        vector<int> rLeafDst = {};
        if(root->left != nullptr) lLeafDst = DFS(root->left, distance);
        if(root->right != nullptr) rLeafDst = DFS(root->right, distance);
        
        int l_size = lLeafDst.size();
        int r_size = rLeafDst.size();
        for(int i=0; i<l_size; i++) {
            for(int j=0; j<r_size; j++) {
                if(lLeafDst[i] + rLeafDst[j] <= distance) ret++;
            }
        }
        
        vector<int> ret;
        for(int i=0; i<l_size; i++) ret.push_back(lLeafDst[i]+1);
        for(int i=0; i<r_size; i++) ret.push_back(rLeafDst[i]+1);
        return ret;
    } 
};