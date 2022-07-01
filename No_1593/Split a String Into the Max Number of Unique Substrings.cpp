class Solution {
public:
    int ret = 0;
    unordered_set<string> hset;
    int maxUniqueSplit(string s) {
        backtracking(s, 0, 0);
        return ret;
    }
    
    void backtracking(string &s, int num, int index) {
        int len = s.length();
        if(len == index) {
            ret = max(ret, num);
            return;
        }
        
        string tmp = "";
        for(int i=index; i<len; i++) {
            tmp += s[i];
            if(hset.find(tmp) != hset.end()) continue;
            hset.insert(tmp);
            backtracking(s, num+1, i+1);
            hset.erase(tmp);
        }
        return;
    }
};