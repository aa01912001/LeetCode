/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr) return head;
        
        while(head != nullptr && head->val == val) { // move head to the node without the value of val
            head = head->next;
        }
        
        if(head == nullptr) return head;
        
        ListNode *pre = head; 
        ListNode *next = head->next;
        while(next != nullptr) { // traverse remaining linked list
            if(next->val == val) {
                pre->next = next->next;
                next = next->next;
                continue;
            }
            
            pre = next;
            next = next->next;
        }
        
        return head;
    }
};