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
    void reorderList(ListNode* head) {
        if(head->next == nullptr) return;
        ListNode* t1 = head;
        ListNode* t2 = head;
                
        while(t2->next != nullptr && t2->next->next != nullptr) {
            t1 = t1->next;
            t2 = t2->next->next;
        }
        
        t2 = t1->next;
        t1->next = nullptr;
        
        t2 = reverse(t2, nullptr);
        
        t1 = head;
        while(t2 != nullptr) {
            ListNode* tn1 = t1->next;
            ListNode* tn2 = t2->next;
            t1->next = t2;
            t2->next = tn1;
            t1 = tn1;
            t2 = tn2;
        }
    
        return;
        
    }
    
    ListNode* reverse(ListNode* t2, ListNode* n) {
        if(t2 == nullptr) return n;
        ListNode* t = t2->next;
        t2->next = n;
        return reverse(t, t2);
    }
};