class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> bMap;
        for(int i=0; i<nums.size(); i++) { // to keep the total points of num
            bMap[nums[i]] += nums[i]; 
        }
        
        int maxWithoutCur = 0, maxWithCur = 0;
        int pre = -1;
        for(auto t : bMap) { // pick from small to large
            int tmp = maxWithoutCur;
            if(t.first -1 != pre) { // if not continous number
                maxWithoutCur = max(maxWithoutCur, maxWithCur);
                maxWithCur = max(tmp, maxWithCur) + t.second;
            } else { // continuous number
                maxWithoutCur = max(maxWithoutCur, maxWithCur);
                maxWithCur = tmp + t.second;
            }
            pre = t.first;
        } 
        
        return max(maxWithoutCur, maxWithCur);
    }
};