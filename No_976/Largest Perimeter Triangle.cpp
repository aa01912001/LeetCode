class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int k=nums.size()-1; k>=2; k--) {
            int i=0, j=k-1;
            while(i<j) {
                if(nums[i] + nums[j] > nums[k]) {
                    return nums[j-1]+nums[j]+nums[k];
                }
                i++;   
            }
        }
        
        return 0;
    }
};