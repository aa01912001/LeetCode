class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> hmap; // <capacity, occupied>
        int ret = 0;
        
        for (int i=0; i<answers.size(); i++) {
            int ans = answers[i];
            if (hmap.find(ans) != hmap.end()) {
                if (hmap[ans] == ans) {
                    // already saturated
                    ret += ans + 1;
                    hmap[ans] = 0;
                } else {
                    hmap[ans]++;
                }
            } else {
                hmap[ans] = 0;
            }
        }
        
        for (auto p : hmap) {
            ret += p.first + 1;
        }
        
        return ret;
    }
};