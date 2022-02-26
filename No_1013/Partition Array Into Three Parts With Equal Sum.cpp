class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum = 0;
        for(int i=0; i<arr.size(); i++) {
            sum += arr[i];
        }
        
        if(sum%3 != 0) return false;
        int target  = sum / 3;
        
        int count = 0;
        int tmp = 0;
        for(int i=0; i<arr.size(); i++) {
            tmp += arr[i];
            if(tmp == target) {
                count++;
                tmp = 0;
            }
        }
        
        return count >= 3;
    }
};