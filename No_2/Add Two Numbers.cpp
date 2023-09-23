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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return add(l1, l2, 0);
    }
    
    ListNode* add(ListNode* l1, ListNode* l2, int carry) {
        if (l1 == nullptr && l2 == nullptr && carry == 0) return nullptr;
        int s1 = l1 != nullptr ? l1->val : 0;
        int s2 = l2 != nullptr ? l2->val : 0;
        int sum = s1 + s2 + carry;
        
        ListNode* newNode = new ListNode(sum % 10);
        
        ListNode* n1 = l1 != nullptr ?  l1->next : nullptr;
        ListNode* n2 = l2 != nullptr ?  l2->next : nullptr;
        newNode->next = add(n1, n2, sum / 10);
        return newNode;
    }
};