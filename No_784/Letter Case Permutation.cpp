class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> ret;
        perm(S, 0, ret);
        return ret;
    }
    
    void perm(string &S, int index, vector<string> &ret) {
        if(index >= S.length()) {
            ret.push_back(S);
            return;
        }
        if(S[index] < 'A') { // if digit
            perm(S, index + 1, ret);
        }else {
            char t = S[index];
            if(S[index] >= 'a' && S[index] <= 'z')  { // if low case
                S[index] -= 32; // 32 is the gap between 'A' and 'a' in ASCII
            } else { // if upper case
                S[index] += 32;
                
            }
            
            perm(S, index + 1, ret); // case with letter changed
            S[index] = t;
            perm(S, index + 1, ret); // original case
        }
        
        return;
    }
};