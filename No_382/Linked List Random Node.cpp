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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        len = 0;
        ListNode *t = head;
        while(t != nullptr) {
            len++;
            list.push_back(t->val);
            t = t->next;
        }  
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int rn = rand() % len;
        return list[rn];
    }
    
private:
    int len;
    vector<int> list;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */