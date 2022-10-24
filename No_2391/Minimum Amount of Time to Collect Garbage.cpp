class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int count = 0;
        int lastIndex[3] = {-1, -1, -1};
        for(int i=0;i <garbage.size(); i++) {
            for(int j=0; j<garbage[i].length(); j++) {
                if(garbage[i][j] == 'M') {
                    lastIndex[0] = i;
                } else if(garbage[i][j] == 'P') {
                    lastIndex[1] = i;
                } else {
                    lastIndex[2] = i;
                }
                count++;
            }
        }
        
        for(int i=1; i<travel.size(); i++) {
            travel[i] += travel[i-1];
        }
        
        int ret = count;
        for(int i=0; i<3; i++) {
            if(lastIndex[i] > 0) {
                ret += travel[lastIndex[i]-1];
            }
        }
        
        return ret;
    }
};