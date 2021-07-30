class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> count(26);
        for(int i=0; i<s.length(); i++) {
            count[s[i] - 'a']++;
        }
        
        for(int i=0; i<s.length(); i++) {
            if(count[s[i] - 'a'] == 1) return i;
        }
        
        return -1;
    }
};