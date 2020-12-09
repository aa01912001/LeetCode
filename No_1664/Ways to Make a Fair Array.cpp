class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        if(nums.size() == 1) return 1;
        int oddSum = 0, evenSum = 0, ret = 0;
        for(int i=0; i<nums.size(); i+=2) oddSum += nums[i]; //  calculate the sum of odd items
        for(int i=1; i<nums.size(); i+=2) evenSum += nums[i]; //  calculate the sum of even items
        int tmpOddSum = 0, tmpEvenSum = 0; //  keep the sum of left and right subarray
        
        for(int i=0; i<nums.size(); i++) {
            if((i+1) % 2 == 1) { //  if i is at odd position
                if(evenSum - tmpEvenSum + tmpOddSum == oddSum - tmpOddSum - nums[i] + tmpEvenSum) {
                    ret++;
                }
                tmpOddSum += nums[i];
            }else { //  if i is at even position
                if(evenSum - tmpEvenSum - nums[i] + tmpOddSum == oddSum - tmpOddSum + tmpEvenSum) {
                    ret++;
                }
                tmpEvenSum += nums[i];
            }
        }
        return ret;
    }
};