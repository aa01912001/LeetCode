class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        
        vector<queue<int>> buckets(10);
        int k = 1;
        while (k != 10) {
            for (int i=0; i<n; i++) {
                buckets[(nums[i]/(int)pow(10, k-1))%10].push(nums[i]);
            }
            
            int index = 0;
            for (int i=0; i<10; i++) {
                while (!buckets[i].empty()) {
                    nums[index] = buckets[i].front();
                    buckets[i].pop();
                    index++;
                }
            }
            k++;
        }
        
        int ret = 0;
        for (int i=1; i<n; i++) {
            ret = max(ret, nums[i]-nums[i-1]);
        }
        
        return ret;
    }
};