class Solution {
private:
    vector<string> key = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
        vector<string> ret;
        DFS(0, "", digits, ret);
        return ret;
    }
    
    void DFS(int index, string curStr, string &digits, vector<string> &ret) {
        if (index == digits.size()) {
            ret.push_back(curStr);
            return;
        }

        for (char c : key[digits[index] - '0']) {
            DFS(index+1, curStr+c, digits, ret);
        }
        
        return;
    }
};