class Solution {
public:
    int minimumPushes(string word) {
        vector<int> counter(26);
        for (char c : word)
            counter[c - 'a']++;
        
        sort(counter.begin(), counter.end(), greater<int>());
        
        int ret = 0, charNum = 0, KEYNUM = 8;
        for (int count : counter) {
            if (count != 0) {
                ret += ((charNum / KEYNUM) + 1) * count;
                charNum++;
            }
        }
        
        return ret;
    }
};