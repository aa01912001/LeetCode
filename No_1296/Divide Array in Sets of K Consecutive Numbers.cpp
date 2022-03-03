class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int, int> mp;
        for(int i=0; i<nums.size(); i++) {
            mp[nums[i]]++;
        }
        
        while(!mp.empty()) {
            vector<int> vec;
            for(auto it=mp.begin(); it!=mp.end() && vec.size()<k; it++) {
                vec.push_back(it->first);
                if(--mp[it->first] == 0) mp.erase(it->first);
            }
            
            if(vec.size() != k) return false;
            for(int i=1; i<vec.size(); i++) {
                if(vec[i]-1 !=vec[i-1]) return false;
            }
        }
        
        return true;
    }
};