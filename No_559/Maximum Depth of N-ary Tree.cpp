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
    int maxDepth(Node* root) {
        int ret = 0, depth = 1;
        DFS(root, depth, ret);
        return ret;
    }
    
    void DFS(Node* root, int depth, int &ret) {
        if(root == nullptr) return;
        ret = max(ret, depth);
        for(int i=0; i<root->children.size(); i++) { //  traversal all children
            DFS(root->children[i], depth+1, ret);
        }
        
        return;
    }
};