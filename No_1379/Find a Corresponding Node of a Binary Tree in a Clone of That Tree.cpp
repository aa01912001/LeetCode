/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private:
    vector<int> dir = {};
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        findTarget(original, target, {});
        TreeNode* tmp = cloned;
        for(int i=0; i<dir.size(); i++) {
            if(dir[i] == 0) {
                tmp = tmp->left;
            } else {
                tmp = tmp->right;
            }
        }
        return tmp;
    }
    
    void findTarget(TreeNode* t, TreeNode* target, vector<int> tmp) {
        if(t == nullptr) return;
        if(t == target) {
            for(int i=0; i<tmp.size(); i++) {
                dir.push_back(tmp[i]);
            }
            return;
        }
        tmp.push_back(0);
        findTarget(t->left, target, tmp);
        tmp.pop_back();
        tmp.push_back(1);
        findTarget(t->right, target, tmp);
    }
};