class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int pre = 0;
        vector<string> ret;
        for(int i=0; i<target.size(); i++) {
            int gap = target[i]-pre-1;
            if(gap > 0) {
                while(gap--) {
                    ret.push_back("Push");
                    ret.push_back("Pop");
                }
            }
            ret.push_back("Push");
            pre = target[i];
        }
        return ret;
    }
};