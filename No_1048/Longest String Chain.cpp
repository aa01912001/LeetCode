class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<int, vector<string>> allLenString; // to keep all strings of all lengths
        unordered_map<string, int> dp; // to keep len of the longest possible word chain where current string is the last one
        sort(words.begin(), words.end(), comp);
        for(int i=0; i<words.size(); i++) {
            allLenString[words[i].size()].push_back(words[i]);
        }
        
        int ret = 1;
        for(int i=0; i<words.size(); i++) {
            dp[words[i]] = 1;
            int preLen = words[i].length()-1;
            for(int j=0; j<allLenString[preLen].size(); j++) {
                if(checkPredecessor(allLenString[preLen][j], words[i])) {
                    dp[words[i]] = max(dp[words[i]], dp[allLenString[preLen][j]]+1);
                    ret = max(ret, dp[words[i]]);
                }
            }
        }
        
        return ret;
    }
    
    static bool comp(string& s1, string& s2) {
        return s1.length() < s2.length();
    }
    
    bool checkPredecessor(string& s1, string& s2) { // check whether s1 is the predecessor s2
        int diff = 0;
        int i = 0, j = 0;
        while(i <= s1.length() && j <= s2.length()) {
            if(s1[i] != s2[j] && diff == 0) {
                j++;
                diff++;
                continue;
            } else if(s1[i] != s2[j]) {
                return false;
            }
            i++;
            j++;
        }
        return true;
    }
    
};