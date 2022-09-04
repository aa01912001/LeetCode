class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-2; i++) {
            if(nums[i] > 0) break;
            // for fear of duplicate number
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int target = -1 * nums[i];
            int left = i + 1, right = nums.size() - 1;
            // using two pointers to find out the pair which has target sum
            while(left < right) {
                int sum = nums[left] + nums[right];
                if(sum == target) {
                    ret.push_back({nums[i], nums[left], nums[right]});
                    // for fear of duplicate number
                    while(left < right && nums[left+1] == nums[left])
                        left++;
                    // for fear of duplicate number
                    while(left < right && nums[right-1] == nums[right])
                        right--;
                    left++;
                    right--;
                } else if(sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        
        return ret;
    }
};