class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> snums(nums.size());
        for(int i=0; i<nums.size(); i++) {
            snums[i] = to_string(nums[i]);
        }
        
        sort(snums.begin(), snums.end(), comparator);
        string ret = "";
        for(int i=0; i<nums.size(); i++) {
            ret += snums[i];
        }
        
        if(ret[0] == '0') return "0";
        
        return ret;
    }
    
    static bool comparator(string &a, string &b) {
        long x = stol(a+b);
        long y = stol(b+a);
        return x > y;
    }
};