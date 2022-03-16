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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode*> hmap;
        ListNode* cur = head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        hmap[0] = dummy;
        int sum = 0;
        while(cur != nullptr) {
            sum += cur->val;
            if (hmap.find(sum) != hmap.end()) {
                ListNode* t = hmap[sum]->next;
                int tmpSum = sum;
                while(t != cur) { // erase those prefix sum of zero sum consecutive nodes
                    tmpSum += t->val;
                    hmap.erase(tmpSum);
                    t = t->next;
                }
                hmap[sum]->next = cur->next;
            } else {
                hmap[sum] = cur;    
            }
            cur = cur->next;
        }
        
        return dummy->next;
    }
};