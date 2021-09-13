class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mn = 1001, mx = 0;
        for(int i=0; i<nums.size(); i++) {
            mn = min(mn, nums[i]);
            mx = max(mx, nums[i]);
        }
        
        return GCD(mn, mx);
    }
    
    int GCD(int a, int b) {
        if(a%b == 0) return b;
            
        return GCD(b, a%b);
    }
};