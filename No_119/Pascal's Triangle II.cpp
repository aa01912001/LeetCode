class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0) {
            return {1};
        } else if(rowIndex == 1) {
            return {1, 1};
        }
        
        vector<int> ret = {1, 1};
        int tmp = 2;
        while(tmp++ <= rowIndex) {
            int t1 = ret[0], t2 = ret[1];
            for(int i=1; i<ret.size(); i++) {
                ret[i] = t1 + t2;
                t1 = t2;
                t2 = ret[i+1];
                
            }
            
            ret.push_back(1);
        }
        
        return ret;
    }
};