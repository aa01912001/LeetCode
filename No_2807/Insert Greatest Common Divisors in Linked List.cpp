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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *p = head;
        while (p->next != nullptr) {
            ListNode *t = new ListNode(getGCD(p->val, p->next->val), p->next);
            p->next = t;
            p = p->next->next;
        }
        
        return head;
    }
    
    int getGCD(int a, int b) {
        if (a % b == 0)
            return b;
        return getGCD(b, a%b);
    }
};