class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        unordered_map<int, int> hmap;
        int sum = 0;
        for(int i=0; i<nums.size(); i++) { // record prefix sum and corresponding index from left
            sum += nums[i];
            hmap[sum] = i;
        }
        
        int n = nums.size();
        int ret = INT_MAX;
        if(hmap.find(x) != hmap.end()) ret = hmap[x]+1; // if x can be reduced to 0 without right elements
        for(int i=n-1; i>=0; i--) { // consider that x can be reduced to 0 when including the different number of right elements 
            x -= nums[i];
            if(x == 0) ret = min(ret, n-i);
            if(x < 0) break;
            if(hmap.find(x) != hmap.end()) {
                if(hmap[x] < i) {
                    ret = min(ret, hmap[x]+1+n-i);    
                }
            }
        }
        
        return ret != INT_MAX ? ret : -1;
    }
};