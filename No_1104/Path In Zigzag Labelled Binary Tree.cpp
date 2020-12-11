class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int h = log(label)/log(2);
        vector<int> ret;
        ret.push_back(label);
        h--;
        while(h>= 0) {
            label = pow(2, h+1) - (label/2 - pow(2, h)) - 1; //  find parent formula
            ret.insert(ret.begin(), label);
            h--;
        }
        
        return ret;
    }
};