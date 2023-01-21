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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        int groupNum = 1, groupCount = 1;
        ListNode *groupHead = head, *groupTail = head;
        while(groupTail != nullptr) {
            if((groupCount == groupNum || groupTail->next == nullptr) && groupCount % 2 == 0) {
                // reverse the current group
                ListNode *reverseHead = groupHead->next, *reverseTail = groupHead->next->next;
                ListNode *pre = groupHead->next;
                while(reverseTail != groupTail) {
                    ListNode *post = reverseTail->next;
                    reverseTail->next = pre;
                    pre = reverseTail;
                    reverseTail = post;
                }
                reverseHead->next = reverseTail->next;
                reverseTail->next = pre;
                groupHead->next = reverseTail;
                groupHead = reverseHead;
                groupTail = reverseHead;
                groupCount = 0;
                groupNum++;
            } else if(groupCount == groupNum) {
                groupHead = groupTail;
                groupCount = 0;
                groupNum++;
            }
            groupTail = groupTail->next;
            groupCount++;
        }

        return head;
    }
};