class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> count;
        for(int i=0; i<arr.size(); i++) { // count the the number of occurrences of each value
            count[arr[i]]++;
        }
        
        unordered_set<int> hset;
        for(auto t : count) { // push different the number of occurrences
            hset.insert(t.second);
        }
        
        if(count.size() == hset.size()) return true;
        
        return false;
    }
};