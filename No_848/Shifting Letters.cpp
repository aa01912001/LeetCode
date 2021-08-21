class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int tmp = 0;
        for(int i=shifts.size()-1; i>=0; i--) {
            tmp += shifts[i]%26;
            s[i] = 'a' + (s[i] - 'a' + tmp)%26;
        }
        
        return s;
    }
};