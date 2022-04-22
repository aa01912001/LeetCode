/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *t = head;
        unordered_map<Node*, Node*> hmap;
        
        while(t != nullptr) {
            Node *newNode = new Node(t->val);
            hmap[t] = newNode;
            t = t->next;
        }
        
        t = head;
        while(t != nullptr) {
            hmap[t]->next = hmap[t->next];
            hmap[t]->random = hmap[t->random];
            t = t->next;
        }
                              
        return hmap[head];
        
    }
};