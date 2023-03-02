class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        
        for(int i=0; i<n/2; i++) {
            swap(nums[i], nums[n-i-1]);
        }
        
        for(int i=0; i<k/2; i++) {
            swap(nums[i], nums[k-i-1]);
        }
        
        for(int i=k; i<(k+(n-k)/2); i++) {
            swap(nums[i], nums[n-i-1+k]);
        }
            
        return;
    }
};