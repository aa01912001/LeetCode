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
class FindElements {
private:
    vector<int> keep;
    
public:
    FindElements(TreeNode* root) {
        DFS(root, 0);
        sort(keep.begin(), keep.end());
        return;
    }
    
    void DFS(TreeNode* root, int i) {
        if(root == nullptr) return;
        root->val = i;
        keep.push_back(i);
        DFS(root->left, 2*i + 1);
        DFS(root->right, 2*i + 2);
    }
    
    bool find(int target) {
        int i=0, j=keep.size()-1;
        while(i <= j) { // binary search
            int mid = (i+j)/2;
            if(keep[mid] == target) {
                return true;
            } else if(keep[mid] < target) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */