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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* minNode = head;
        ListNode* tail = head;
        while(tail->next != nullptr) {
            if(tail->next->val >= tail->val) { // target node is unnecessary to move
                tail = tail->next;
                continue;
            }
            ListNode* target = tail->next;
            ListNode* tmp = minNode;
            if(minNode->val > target->val) { // target node has the minimum value
                tail->next = target->next;
                target->next = minNode;
                minNode = target;
            } else {
                while(tmp != tail) { // target node should be insert into somewhere between front and tail
                    if(tmp->next->val > target->val) {
                        tail->next = target->next;
                        target->next = tmp->next;
                        tmp->next = target;
                        break;
                    }
                    tmp = tmp->next;
                }    
            }
        }
        return  minNode;
    }
};