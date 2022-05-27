class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.length();
        int ret = 0;
        vector<int> preCount(n+1);    
        for(int i=0; i<n ; i++) {
            preCount[i+1] = preCount[i] + isVowel(s[i]);
            if(i < k-1) continue;
            ret = max(ret, preCount[i+1]-preCount[i+1-k]);
        }
        
        return ret;
    }
    
    int isVowel(char c) {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return 1;
        return 0;
    }
};