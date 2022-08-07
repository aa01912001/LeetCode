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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr;
        return divide(lists, 0, lists.size()-1);
    }
    
    ListNode* divide(vector<ListNode*>& lists, int start, int end) {
        // using merge sort to sort lists[start] to lists[end]
        if(start == end) return lists[start];
        int mid = (start + end) / 2;
        ListNode *leftList = divide(lists, start, mid);
        ListNode *rightList = divide(lists, mid+1, end);
        return merge(leftList, rightList);
    }
    
    ListNode* merge(ListNode *leftList, ListNode *rightList) {
        ListNode *dummy = new ListNode();
        ListNode *last = dummy;
        while(leftList != nullptr && rightList != nullptr) {
            // merge two lists
            if(leftList->val <= rightList->val) {
                last->next = leftList;
                last = last->next;
                leftList = leftList->next;
            } else {
                last->next = rightList;
                last = last->next;
                rightList = rightList->next;
            }
        }
        
        // cascading the remaining list
        if(leftList != nullptr) last->next = leftList;
        if(rightList != nullptr) last->next = rightList;
        
        return dummy->next;
    }
};