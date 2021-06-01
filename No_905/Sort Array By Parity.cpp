class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> even, odd;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]%2) {
                odd.push_back(nums[i]);
            } else {
                even.push_back(nums[i]);
            }
        }
        
        for(int i=0; i<odd.size(); i++) {
            even.push_back(odd[i]);
        }
        
        return even;
    }
    

};