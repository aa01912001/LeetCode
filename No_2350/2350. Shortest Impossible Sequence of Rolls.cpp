class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        int count = 0;
        unordered_set<int> hset;
        for (int num : rolls) {
            hset.insert(num);
            if (hset.size() == k) {
                hset.clear();
                count++;
            }
        }
        
        return count + 1;
    }
};