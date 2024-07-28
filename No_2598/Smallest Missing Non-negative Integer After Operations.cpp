class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> count;
        
        for (int num : nums) {
            count[(num % value + value) % value]++;
        }
        
        int modValue = 0;
        for (int i = 0; i < value; i++) {
            if (count[i] < count[modValue])
                modValue = i;
        }
        
        return modValue + (value * count[modValue]);
    }
};