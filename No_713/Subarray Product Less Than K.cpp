class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int product = nums[0];
        int ret = 0;
        int n = nums.size();
        int left = 0, right = 0;

        while(1) {
            if(product < k) {
                ret += right - left + 1;
                if(++right == n) break;
                product *= nums[right];
            } else {
                if(left == right) {
                    if(++right == n) break;
                    product *= nums[right];
                } else {
                    product /= nums[left++];
                }
            }
        }

        return ret;
    }
};