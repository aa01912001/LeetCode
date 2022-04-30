class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mn = INT_MAX, mx = INT_MIN;
        int lo1 = -1, lo2 = -1;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            int num = nums[i];
            if(mn > num) {
                mn = num;
                lo1 = i;
            }
            
            if(mx < num) {
                mx = num;
                lo2 = i;
            }
        }
        
        if(lo1 == lo2) return 1;
        
        if(lo1 > lo2) { // let lo1 lower index and lo2 higher index
            int t = lo1;
            lo1 = lo2;
            lo2 = t;
        } 
        
        int ret = INT_MAX;
        ret = min(ret, (lo1+1)+(n-lo2));
        ret = min(ret, lo2+1);
        ret = min(ret, n-lo1);
        
        return ret;
        
    }
};