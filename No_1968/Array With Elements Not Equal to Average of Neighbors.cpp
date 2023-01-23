class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int mid  = n / 2;
        sort(nums.begin(), nums.end());
        vector<int> ret(n);

        for(int i=0; i<mid; i++) {
            ret[i*2] = nums[mid+i];
            ret[i*2+1] = nums[i];
        }

        if(n % 2 == 1)
            ret[n-1] = nums[n-1];

        return ret;
    }
};