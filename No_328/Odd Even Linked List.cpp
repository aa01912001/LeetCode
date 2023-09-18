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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        
        ListNode *oddTail = head, *evenTail = head->next, *evenHead = head->next;
        while (evenTail != nullptr && evenTail->next != nullptr) {
            oddTail->next = evenTail->next;
            evenTail->next = evenTail->next->next;
            
            oddTail = oddTail->next;
            evenTail = evenTail->next;
        }
        
        oddTail->next = evenHead;
        return head;
    }
};