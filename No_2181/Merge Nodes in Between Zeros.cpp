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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* newList = head;
        ListNode* pre = newList;
        
        head = head->next;
        int tmp = 0;
        while(head != nullptr) {
            if(head->val == 0) {
                head->val = tmp;
                pre->next = head;
                pre = head;
                tmp = 0;
            } else {
                tmp += head->val;
            }
            head = head->next;
        }
        
        return newList->next;
    }
};