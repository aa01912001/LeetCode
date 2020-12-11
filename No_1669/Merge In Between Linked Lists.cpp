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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *t1 = list1, *t2 = list2;
        while(t2->next) { //  find the last node of list2
            t2 = t2->next;
        }
        
        int i=0;
        while(i++ != a-1) { // find pre-node of ath node
            t1 = t1->next;
        }
        ListNode *t3 = t1->next; // let t3 points to ath node
        t1->next = list2;
        
        while(i++ != b) { // find the bth node
            t3 = t3->next;
        }
        
        t2->next = t3->next;
        
        return list1;
        
    }
};