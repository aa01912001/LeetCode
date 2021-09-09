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
class CBTInserter {
private:
    vector<TreeNode*> seq;
    int count = 1;
public:
    CBTInserter(TreeNode* root) {
        seq.push_back(new TreeNode());
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* tmp = q.front();
            seq.push_back(tmp);
            count++;
            if(tmp->left) q.push(tmp->left);
            if(tmp->right) q.push(tmp->right);
            q.pop();
        }
        
    }
    
    int insert(int val) {
        TreeNode* t = new TreeNode(val);
        if(seq[count/2]->left == nullptr) {
            seq[count/2]->left = t;
        } else {
            seq[count/2]->right = t;
        }
        seq.push_back(t);
        count++;
        return seq[(count-1)/2]->val;
    }
    
    TreeNode* get_root() {
        return seq[1];
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */