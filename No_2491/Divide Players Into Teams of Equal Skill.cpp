class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long ret = 0;
        int target = accumulate(skill.begin(), skill.end(), 0) / (skill.size() / 2);
        unordered_map<int, int> hmap;
        
        for (int num : skill) {
            int gap = target - num;
            if (hmap.find(gap) != hmap.end()) {
                hmap[gap] -= 1;
                if (hmap[gap] == 0)
                    hmap.erase(gap);
                ret += num * gap;
            } else {
                hmap[num]++;
            }
        }

        return hmap.size() == 0 ? ret : -1;
    }
};