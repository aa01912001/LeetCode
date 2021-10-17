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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *preGroupTail = new ListNode(-1);
        preGroupTail->next = head;
        ListNode *traverse = preGroupTail;
        int t = k; // the counter of traversed nodes
        ListNode *ret = head;
        bool firstGroup = true;
        while(traverse->next != nullptr) {
            traverse = traverse->next;
            t--;
            if(t == 0) { // traverse k nodes
                ListNode* tmp = preGroupTail->next;
                preGroupTail->next = reverse(preGroupTail->next, traverse->next, k);
                if(firstGroup) { // if firstGroup, we have to return the first node of firstGroup
                    ret = preGroupTail->next;
                    firstGroup = false;
                }
                preGroupTail = tmp;
                traverse = tmp;
                t = k;
            }
        }
        
        return ret;
    }
    
    ListNode* reverse(ListNode* curr, ListNode* next, int k) {
        if(k == 0) {
            return next; // return first node after reverse
        }
        
        ListNode* t = curr->next;
        curr->next = next;
        return reverse(t, curr, k-1);
    }
};