class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> freq(51), ret;
        for (int i=0; i<n; i++) {
            if (nums[i] < 0) {
                freq[abs(nums[i])]++;
            }
            if (i - k >= 0 && nums[i-k] < 0) {
                freq[abs(nums[i-k])]--;
            }
            
            if (i >= k - 1) {
                int count = 0;
                for (int j=50; j>0; j--) {
                    count += freq[j];
                    if (count >= x) {
                        ret.push_back(-1 * j);
                        break;
                    }
                }
                if (count < x)
                    ret.push_back(0);
            }
        }
        
        return ret;
    }
};