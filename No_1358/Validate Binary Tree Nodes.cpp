class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> hmap;
        int n = s.length();
        int ret = 0;
        int left = 0, right = 0;
        
        hmap[s[0]]++;
        while(right < n) {
            if(hmap.size() < 3) {
                right++;
                hmap[s[right]]++;
            } else {
                ret += n - right;
                hmap[s[left]]--;
                if(hmap[s[left]] == 0) hmap.erase(s[left]);
                left++;
            }
        }
        
        return ret;
    }
};