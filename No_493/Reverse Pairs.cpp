class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
    
    int mergeSort(vector<int>& nums, int l, int r) {
        if(l == r) return 0;
        int mid = l + (r-l)/2;
        int cnt = mergeSort(nums, l, mid) + mergeSort(nums, mid+1, r); // divide
        for(int i=l, j=mid+1; i<=mid; i++) {
            while(j<=r && nums[i] > 2*long(nums[j])) j++;
            cnt += j - (mid + 1);
        }
        
        sort(nums.begin()+l, nums.begin()+r+1); // merge
        
        return cnt;
    }
};