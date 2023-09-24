class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(), ret = 0;
        unordered_map<char, int> hmap;
        
        int left = 0, right = 0;
        while (right < n) {
            hmap[s[right]]++;
            while (checkOverFlow(hmap, k)) {
                hmap[s[left]]--;
                left++;
            }
            ret = max(ret, right - left + 1);
            right++;
        }
        
        return ret;
    }
    
    bool checkOverFlow(unordered_map<char, int>&hmap, int k) {
        int total = 0, maxFreq = 0;
        for (auto p : hmap) {
            total += p.second;
            maxFreq = max(maxFreq, p.second);
        }
        
        return total - maxFreq > k;
    }
};