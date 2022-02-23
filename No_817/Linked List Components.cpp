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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_map<int, bool> hmap;
        for(int i=0; i<nums.size(); i++) {
            hmap[nums[i]] = true;
        }
        
        bool inNums = false;
        int ret = 0;
        while(head != nullptr) {
            if(hmap[head->val]) {
                if(!inNums) ret++;
                inNums = true;
            } else {
                inNums = false;
            }
            head = head->next;
        }
        
        return ret;
    }
};