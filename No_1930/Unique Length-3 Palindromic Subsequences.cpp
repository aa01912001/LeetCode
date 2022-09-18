class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ret = 0;
        vector<pair<int, int>> v(26, {-1, -1}); // to record starting and ending index of each char
        for (int i=0; i<s.length(); i++) {
            if (v[s[i]-'a'].first == -1)
                v[s[i]-'a'].first = i;
            else 
                v[s[i]-'a'].second = i;
        }
        
        for (int i=0; i<26; i++) {
            if (v[i].second == -1) continue; // appear only zero or one time
            unordered_set<char> hset;
            for (int j=v[i].first+1; j<v[i].second; j++) // record different char between starting and ending index
                hset.insert(s[j]);
            ret += hset.size();
        }
        
        return ret;
    }
};