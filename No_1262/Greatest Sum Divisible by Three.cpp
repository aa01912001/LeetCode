class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum0 = 0, sum1 = 0, sum2 = 0;
        for(int i=0; i<nums.size(); i++) {
            int n_sum0 = 0, n_sum1 = 0, n_sum2 = 0;
            if(nums[i]%3 == 1) {
                if(sum2%3 != 0) {
                    n_sum0 = max(sum0, sum2 + nums[i]);    
                } else {
                    n_sum0 = sum0;
                }
                
                n_sum1 = max(sum1, sum0 + nums[i]);    
                
                if(sum1%3 != 0) {
                    n_sum2 = max(sum2, sum1 + nums[i]);    
                } else {
                    n_sum2 = sum2;
                }
                
            } else if(nums[i]%3 == 2) {
                if(sum1%3 != 0) {
                    n_sum0 = max(sum0, sum1 + nums[i]);
                } else {
                    n_sum0 = sum0;
                }
                
                if(sum2%3 != 0) {
                    n_sum1 = max(sum1, sum2 + nums[i]);   
                    
                } else {
                    n_sum1 = sum1;
                }
                
                n_sum2 = max(sum2, sum0 + nums[i]);
                
            } else {
                n_sum0 = sum0 + nums[i];
                n_sum1 = sum1 + nums[i];
                n_sum2 = sum2 + nums[i];
            }
            sum0 = n_sum0;
            sum1 = n_sum1;
            sum2 = n_sum2;
        }
        
        return sum0;
    }
};