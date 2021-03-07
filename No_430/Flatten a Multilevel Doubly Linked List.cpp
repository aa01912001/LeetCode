/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head == nullptr) return head;
        helper(head, nullptr);
        return head;
    }
    
    Node* helper(Node* head, Node* pre) {
        if(pre != nullptr) { // link different level node
            head->prev = pre;
            pre->next = head;
        }
        
        if(head->child == nullptr && head->next == nullptr) return head;
        
        if(head->child == nullptr) { // traverse child level
           return helper(head->next, nullptr);
        } 
        
        Node* pre_next = head->next;
        head->next = head->child;
        pre = helper(head->child, head); // get last node to link with original head->next
        head->child = nullptr;
        if(pre_next == nullptr) { // for fear that link with nullptr
            return pre;
        }
        
        return helper(pre_next, pre);
            
    }
};