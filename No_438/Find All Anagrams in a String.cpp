class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int left = 0, right = 0, matchCount = p.size();
        vector<int> ret;
        unordered_map<char, int> hmap;
        
        for (char c : p) hmap[c]++;
        while (right < s.size()) {
            if (hmap[s[right++]]-- >= 1) matchCount--;
            if (matchCount == 0) ret.push_back(left);
            if (right - left == p.size() && hmap[s[left++]]++ >= 0) matchCount++;
        }
        
        return ret;
    }
};