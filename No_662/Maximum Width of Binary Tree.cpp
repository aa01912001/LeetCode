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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        int ret = 0;
        while(!q.empty()) {
            int size = q.size();
            int mn = INT_MAX, mx = 0;
            int firstIndex = q.front().second; // to avoid overflow of int
            for(int i=0; i<size; i++) {
                auto t = q.front();
                q.pop();
                long long int curIndex = t.second-firstIndex;
                if(t.first->left != nullptr) q.push({t.first->left, curIndex*2});
                if(t.first->right != nullptr) q.push({t.first->right, curIndex*2+1});
                if(i == 0) mn = curIndex;
                if(i == size-1) mx = curIndex;
            }
            ret = max(ret, mx-mn+1);
        }
        return ret;
    }
};