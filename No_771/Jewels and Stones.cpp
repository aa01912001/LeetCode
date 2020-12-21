class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char, int> hash;
        int ret = 0;
        
        for(int i=0; i<stones.length(); i++) {
            hash[stones[i]]++;
        }
        
        for(int i=0; i<jewels.length(); i++) {
            ret += hash[jewels[i]];
        }
        
        return ret;
    }
};