class Solution {
private:
    static bool compare(vector<int> a, vector<int> b) {
        return a[1] > b[1];
    }
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), compare);
        int ret = 0;
        
        for(int i=0; i<boxTypes.size(); i++) {
            if(truckSize > 0) {
                if(boxTypes[i][0] <= truckSize) {
                    ret += boxTypes[i][0] * boxTypes[i][1];
                    truckSize -= boxTypes[i][0];
                } else {
                    ret += truckSize * boxTypes[i][1];
                    truckSize = 0;
                }    
            } else {
                break;
            }
        }
        return ret;
    }
};