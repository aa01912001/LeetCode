class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int prefixProduct = 1;
        vector<int> ret(n);
        for(int i=0; i<n; i++) {
            ret[i] = prefixProduct;
            prefixProduct *= nums[i]; 
        }
        prefixProduct = 1;
        for(int i=n-1; i>=0; i--) {
            ret[i] *= prefixProduct;
            prefixProduct *= nums[i]; 
        }
        return ret;
    }
};