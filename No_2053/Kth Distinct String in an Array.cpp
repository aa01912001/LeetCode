class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> count;
        for(int i=0; i<arr.size(); i++) {
            count[arr[i]]++;
        }
        for(int i=0; i<arr.size(); i++) {
            if(count[arr[i]] == 1) {
                if(--k == 0) {
                    return arr[i];
                }
            }
        }
        
        return "";
        
    }
};