class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ret;
        for (int i=1; i<=9; i++) {
            backtracking(ret, to_string(i), n, k);
        }
        return ret;
    }
    
    void backtracking(vector<int> &ret, string num, int n, int k) {
        if (num.length() == n) {
            ret.push_back(stoi(num));
            return;
        }
        
        int preDigit = num[num.length()-1] - '0';
        if (preDigit - k >= 0) {
            backtracking(ret, num + to_string(preDigit - k), n, k);
        }
        
        if (k != 0 && preDigit + k <= 9) {
            backtracking(ret, num + to_string(preDigit + k), n, k);
        }
        
        return;
    }
};