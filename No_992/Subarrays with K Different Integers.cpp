class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       return subarraysAtMostKDistinct(nums, k) - subarraysAtMostKDistinct(nums, k-1); 
    }
    
    int subarraysAtMostKDistinct(vector<int>& nums, int k) {
        int ret = 0;
        int left = 0;
        unordered_map<int, int> hmap;
        for(int i=0; i<nums.size(); i++) {
            if(hmap[nums[i]] == 0) 
                k--;
            hmap[nums[i]]++;
            while(k < 0) {
                if(--hmap[nums[left]] == 0)
                    k++;
                left++;
            }
            ret += i - left + 1;

        }
        return ret;
    }
};