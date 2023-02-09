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
    unordered_map<int, priority_queue<pair<int, int>>> levelDownPath;
    unordered_map<int, int> nodeLevel;
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        DFS(root->left, 1);
        DFS(root->right, 1);

        int n = queries.size();
        vector<int> ret(n);
        for(int i=0; i<n; i++) {
            int node = queries[i];
            int level = nodeLevel[node];
            auto top = levelDownPath[level].top(); 
            levelDownPath[level].pop();
            if(top.second == node) {
                if(levelDownPath[level].empty()) {
                    ret[i] = level - 1;
                } else {
                    ret[i] = level + levelDownPath[level].top().first;
                }
            } else {
                
                ret[i] = level + top.first;
            }
             levelDownPath[level].push(top);
        }

        return ret;
    }

    int DFS(TreeNode* root, int level) {
        if(root == nullptr) return 0;
        nodeLevel[root->val] = level;

        int maxDownPath = max(DFS(root->left, level+1), DFS(root->right, level+1));
        levelDownPath[level].push({maxDownPath, root->val});

        return maxDownPath + 1;
    }
};