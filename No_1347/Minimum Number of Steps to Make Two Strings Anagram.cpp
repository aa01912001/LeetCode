class Solution {
public:
    int minSteps(string s, string t) {
        int count[26] = {};
        int ret = 0;
        for(int i=0; i<s.length(); i++) { // count the number of each char in s
            count[s[i]-'a']++;
        }
        
        for(int i=0; i<t.length(); i++) { // substract the number of each char in t
            count[t[i]-'a']--;
        }
        
        for(int i=0; i<26; i++) { // count the total sum of each char in count
            ret += abs(count[i]);
        }
        
        return ret/2;
    }
};