unordered_map<int, int> hmap;
class Solution {
public:
    
    static bool comparator(int a, int b) {
        return hmap[a]<hmap[b] || (hmap[a] == hmap[b] && a > b);
    }

    vector<int> frequencySort(vector<int>& nums) {
        hmap.clear();
        for(int i=0; i<nums.size(); i++) {
            hmap[nums[i]]++;
        }
        
        sort(nums.begin(), nums.end(), comparator);
        return nums;
    }
};