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
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        
        ListNode *slow = head, *fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        fast = slow->next;
        slow->next = nullptr;
        
        return mergeLists(sortList(fast), sortList(head));
    }
    
    ListNode* mergeLists(ListNode* head1, ListNode* head2) {
        ListNode* dummy = new ListNode();
        ListNode* pre = dummy;
        while (head1 != nullptr && head2 != nullptr) {
            if (head1->val < head2->val) {
                pre->next = head1;
                head1 = head1->next;
            } else {
                pre->next = head2;
                head2 = head2->next;
            }
            pre = pre->next;
        }
        
        pre->next = head1 != nullptr ? head1 : head2;
        
        return dummy->next;
    }    
};