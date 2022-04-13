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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* pre = dummy; // pre: points to previous unique node
        while(pre->next) {
            ListNode* tmp = pre->next;
            bool isDup = false;
            while(1) {
                if(tmp->next == nullptr || tmp->next->val != tmp->val) {
                    if(!isDup) { // this is unique node
                        pre = pre->next;
                    } else { // remove duplicates 
                        pre->next = tmp->next;
                    }
                    break;
                }
                tmp = tmp->next;
                isDup = true;
            }
        }
        return dummy->next;
    }
};