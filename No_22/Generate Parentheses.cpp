class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        generate(n, n, ret, "");
        return ret;
    }
    
    void generate(int left, int right, vector<string>& ret, string tmp) {
        if(left == 0 && right == 0) {
            ret.push_back(tmp);
            return;
        }
        
        if(left != 0) {
            generate(left-1, right, ret, tmp+"(");    
        }
        
        if(left < right) {
            generate(left, right-1, ret, tmp+")");    
        }
        
        return;
    }
};