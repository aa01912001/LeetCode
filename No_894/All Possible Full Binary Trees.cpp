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
    unordered_map<int, vector<TreeNode*>> hmap; // to keep the sub solution
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> ret;
        if(hmap[n].size() != 0) {
            return hmap[n];
        }
        
        if(n == 1) {
            TreeNode *t = new TreeNode();
            hmap[n].push_back(t);
        } else {
            for(int i=1; i<=n-2; i+=2) { // possible number of left subtree
                for(TreeNode* l : allPossibleFBT(i)) {
                    for(TreeNode* r : allPossibleFBT(n-1-i)) {
                        TreeNode *t = new TreeNode(); // build new tree
                        t->left = l;
                        t->right = r;
                        hmap[n].push_back(t);
                    }
                }
            }
        }
        
        return hmap[n];
    }
    
    
};