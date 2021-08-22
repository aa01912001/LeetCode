class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> count1(26, 0), count2(26, 0);
        int m = s1.length(), n = s2.length();
        for(int i=0; i<m; i++) {
            count1[s1[i]-'a']++;
        }
        
        for(int i=0; i<n; i++) {
            count2[s2[i]-'a']++;
            if(i >= m) count2[s2[i-m]-'a']--;
            if(count1 == count2) return true;
        }
        
        return false;
    }
};