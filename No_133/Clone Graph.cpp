/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    unordered_map<int, Node*> hmap;
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        Node *n = new Node(node->val);
        hmap[n->val] = n;
        for(int i=0; i<node->neighbors.size(); i++) {
            if(hmap.find(node->neighbors[i]->val) != hmap.end()){
                n->neighbors.push_back(hmap[node->neighbors[i]->val]);    
            } else {
                n->neighbors.push_back(cloneGraph(node->neighbors[i]));    
            }
        }
        
        return n;
    }
};