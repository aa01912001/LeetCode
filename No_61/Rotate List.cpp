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
    ListNode* rotateRight(ListNode* head, int k) {
        int len = 0;
        ListNode* t = head;
        while(t != nullptr) { // count list len
            t = t->next;
            len++;
        }
        
        if(len == 0 || len == 1 || k == 0 || k%len == 0) return head; // if don't shift
        int shift = len - (k % len);
        int i = 0;
        ListNode* h1 = head;
        while(i++ != shift) {
            h1=h1->next;
        }
        
        t = h1;
        while(t->next != nullptr) {
            t = t->next;
        }
        t->next = head;
        int j=0;
        while(j++ != shift-1) {
            head = head->next;
        }
        head->next = nullptr;
        
        return h1;
    }
};