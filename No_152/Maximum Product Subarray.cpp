class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ret = nums[0];
        int curMaxProduct = nums[0], curMinProduct = nums[0];
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] < 0)
                swap(curMaxProduct, curMinProduct);
            curMaxProduct = max(nums[i], curMaxProduct*nums[i]);
            curMinProduct = min(nums[i], curMinProduct*nums[i]);
            ret = max(ret, curMaxProduct);
        }
        return ret;
    }
};