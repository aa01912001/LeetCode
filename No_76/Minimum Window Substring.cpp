class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> charCount;
        int numOfIncludedChar = 0, minIndex = -1, minLen = INT_MAX;
        
        for (char c : t) charCount[c]++;
        int left = 0;
        for (int right = 0; right < s.length(); right++) {
            if (--charCount[s[right]] >= 0) numOfIncludedChar++;
            while (numOfIncludedChar == t.size()) {
                if (minLen > right - left + 1) {
                    minLen  = right - left + 1;
                    minIndex = left;
                }
                
                if (++charCount[s[left]] > 0) numOfIncludedChar--;
                left++;
            }
        }
        
        return minIndex == -1 ? "" : s.substr(minIndex, minLen);
    }
};