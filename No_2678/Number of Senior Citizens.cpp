class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ret = 0;
        for (string d : details) {
            if (stoi(d.substr(11, 2)) > 60)
                ret++;
        }
        
        return ret;
    }
};