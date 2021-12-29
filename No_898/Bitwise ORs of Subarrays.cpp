class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> ret, pre;
        for(int i=0; i<arr.size(); i++) {
            unordered_set<int> cur;
            
            for(int t : pre) {
                cur.insert(t|arr[i]);
            }
            cur.insert(arr[i]);
            
            for(int t : cur) {
                ret.insert(t);
            } 
            pre = cur;
        }
        
        return ret.size();
    }
};