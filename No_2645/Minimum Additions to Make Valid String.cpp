class Solution {
public:
    int addMinimum(string word) {
        int len = word.length();
        int ret = len * 2;
        for (int i=1; i<len; i++) {
            switch (word[i]) {
            case 'a':
                break;
            case 'b':
                if (word[i-1] == 'a') ret -= 3;
                break;
            case 'c':
                if (word[i-1] != 'c') ret -= 3;
                break;
            }
        }
        
        return ret;
    }
};