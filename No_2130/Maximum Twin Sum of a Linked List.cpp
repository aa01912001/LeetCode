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
    int pairSum(ListNode* head) {
        ListNode* slower = head;
        ListNode* faster = head->next;
        while(faster->next != nullptr) {
            slower = slower->next;
            faster = faster->next->next;
        }
        
        faster = head;
        slower = reverse(slower);
        
        int ret = 0;
        while(slower->next != nullptr) {
            ret = max(ret, faster->val+slower->val);
            faster = faster->next;
            slower = slower->next;
        }
        return ret;
    }
    
    ListNode* reverse(ListNode* node) {
        if(node == nullptr || node->next == nullptr) return node;
        ListNode* n = node->next;
        ListNode* ret = reverse(node->next);
        n->next = node;
        node->next = nullptr;
        return ret;
    } 
};