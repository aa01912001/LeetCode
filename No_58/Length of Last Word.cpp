class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string tmp;
        while(!ss.eof())
            ss >> tmp;
        return tmp.length();
        
    }
};