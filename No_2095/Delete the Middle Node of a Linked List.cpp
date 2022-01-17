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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return nullptr;
        ListNode* slower = head;
        ListNode* faster = head->next;
        while(faster->next && faster->next->next) {
            slower = slower->next;
            faster = faster->next->next;
        }
        
        slower->next = slower->next->next;
        return head;
    }
};