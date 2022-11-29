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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> stk;
        while(head != nullptr) {
            while(!stk.empty() && head->val > stk.top()->val) {
                stk.pop();
            }
            stk.push(head);
            head = head->next;
        }
        
        ListNode* ret = nullptr;
        while(!stk.empty()) {
            stk.top()->next = ret;
            ret = stk.top();
            stk.pop();

        }
        
        return ret;
    }
    
};