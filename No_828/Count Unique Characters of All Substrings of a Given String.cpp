class Solution {
public:
    int uniqueLetterString(string s) {
        unordered_map<char, int> hmap;
        int n = s.length(), ret = 0;
        vector<int> preIndexes(n, -1), postIndexes(26, n);
        
        for (int i = 0; i < n; i++) {
            if (hmap.find(s[i]) != hmap.end()) {
                preIndexes[i] = hmap[s[i]];    
            }
            hmap[s[i]] = i;
        }

        for (int i = n - 1; i >= 0; i--) {
            int pre = preIndexes[i], post = postIndexes[s[i]-'A'];
            ret += i - pre;
            ret += post - i - 1;
            ret += (i - pre - 1) * (post - i - 1);
            postIndexes[s[i]-'A'] = i;   
        }
        
        return ret;
    }
};