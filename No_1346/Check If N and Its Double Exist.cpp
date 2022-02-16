class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> hset;
        for(int i=0; i<arr.size(); i++) {
            if(find(hset.begin(), hset.end(), arr[i]*2.) != hset.end() ||
               find(hset.begin(), hset.end(), arr[i]/2.) != hset.end()) {
                return true;
            }
            hset.insert(arr[i]);
        }
        
        return false;
    }
};