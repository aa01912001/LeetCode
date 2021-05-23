/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> ret;
        doPostorder(root, ret);
        return ret;
    }
    
    void doPostorder(Node* root, vector<int>& ret) {
        if(root == nullptr) return;
        for(int i=0; i<(root->children).size(); i++) {
            doPostorder((root->children)[i], ret);    
        }
        ret.push_back(root->val);
        return;
    }
};