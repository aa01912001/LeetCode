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
    vector<int> nextLargerNodes(ListNode* head) {
        stack<pair<int, int>> s;
        vector<int> ret;
        int index = 0;
        
        while(head != nullptr) {
            ret.push_back(0);
            while(!s.empty() && s.top().first < head->val) {
                ret[s.top().second] = head->val;
                s.pop();
            }
        
            s.push(make_pair(head->val, index));
            head = head->next;
            index++;
        }
        
        return ret;
    }
};