class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int len = nums.size();
        vector<int> result(len, 0);
        
        for(int i=0; i<len; i++) { // calculate the result[0]
            result[0] += nums[i] - nums[0];
        }
        
        for(int i=1; i<len; i++) { // calculate the result[1] ~ result[last]
            result[i] = result[i-1] + (nums[i]-nums[i-1])*i - (nums[i]-nums[i-1])*(len-i);  
        }
        
        return result;
    }
};