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
    ListNode* last;
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        head = dummy;
        int t = left;
        while(--t) {
            head = head->next;
        }
        reverse(head->next, right-left);
        head->next = last;
        return dummy->next;
    }
    
    ListNode* reverse(ListNode* head, int n) {
        if(n == 0) {
            last = head;
            return head->next;
        }
        ListNode* tmp = head->next;
        ListNode* rightNode = reverse(tmp, n-1);
        tmp->next = head;
        head->next = rightNode;
        return rightNode;
    }
};