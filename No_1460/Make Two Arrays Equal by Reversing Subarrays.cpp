class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> counter1, counter2;
        for (int i = 0; i < target.size(); i++) {
            counter1[target[i]]++;
            counter2[arr[i]]++;
        }
        
        return counter1 == counter2;
    }
};