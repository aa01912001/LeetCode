class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ret = "";
        for(int i=0; i<nums.size(); i++) {
            nums[i][i] == '0' ? ret += '1' : ret += '0';
        }
        
        return ret;
    }
};