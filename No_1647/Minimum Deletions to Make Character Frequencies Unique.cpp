class Solution {
public:
    int minDeletions(string s) {
        int ret = 0;
        vector<int> count(26);
        for(int i=0; i<s.length(); i++) {
            count[s[i]-'a']++;
        }
        sort(count.begin(), count.end());
        for(int i=24; i>=0; i--) {
            if(count[i] == 0) break;
            if(count[i] >= count[i+1]) {
                if(count[i+1] == 0) {
                    ret += count[i];
                    count[i] = 0;
                    continue;
                }
                ret += count[i] - count[i+1] + 1;
                count[i] = count[i+1] - 1;
            }
        }
        
        return ret;
    }
};