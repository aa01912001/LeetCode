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
    ListNode* partition(ListNode* head, int x) {
        ListNode* ls = new ListNode(-1);
        ListNode* lsRunner = ls;
        ListNode* ge = new ListNode(-1);
        ListNode* geRunner = ge;
        
        while(head != nullptr) {
            if(head->val < x) {
                lsRunner->next = head;
                lsRunner = head;
            } else {
                geRunner->next = head;
                geRunner = head;
            }
            
            head = head->next;
        }
        
        geRunner->next = nullptr;
        lsRunner->next = ge->next;
        return ls->next;
    }
};