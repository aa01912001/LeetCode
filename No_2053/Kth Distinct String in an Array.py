class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> counter;
        for (string s : arr)
            counter[s]++;
        
        for (string s : arr) {
            if (counter[s] == 1) {
                if (k == 1)
                    return s;
                k--;
            }
        }
        
        return "";
    }
};