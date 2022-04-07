/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr) return nullptr;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            Node* pre;
            while(size--) {
                pre = q.front();
                q.pop();
                if(pre->left != nullptr) q.push(pre->left);
                if(pre->right != nullptr) q.push(pre->right);
                if(size != 0) pre->next = q.front();
            }
            pre->next = nullptr;
        }
        return root;
    }
};