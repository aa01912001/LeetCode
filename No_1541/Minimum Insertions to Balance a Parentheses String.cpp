class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        int scores = 0;
        int index = 0;
        int ret = 0;
        
        while(index < n) {
            while(index < n && s[index] != '(') {
                scores -= 1;
                index++;
            }
            if(index >= n) break;
            if(scores < 0) {
                (-1*scores) % 2 == 1 ? ret += -1 * scores / 2 + 2: ret += -1 * scores / 2. + 0.5;
                scores = 0;
            }
            scores += 2;
            if(scores % 2 == 1) {
                scores -= 1;
                ret++;
            }
            index++;
        }
        
        if(scores < 0) {
            (-1*scores) % 2 == 1 ? ret += -1 * scores / 2 + 2: ret += -1 * scores / 2. + 0.5;
        } else {
            ret += scores;
        }
        
        return ret; 
    }
};