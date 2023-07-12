class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        unordered_map<int, int> numCount, freqCount;
        int ret = 1;
        
        for (int i = 0; i < nums.size(); i++) {
            numCount[nums[i]]++;
            
            int newCount = numCount[nums[i]];
            freqCount[newCount] += newCount;

            if (newCount != 1) {
                freqCount[newCount-1] -= newCount - 1;
                if (freqCount[newCount-1] == 0)
                    freqCount.erase(newCount-1);
            }
            
            if (freqCount.size() == 2) {
                vector<int> freqs(2), counts(2);
                int index = 0;
                for (auto p : freqCount) {
                    freqs[index] = p.first;
                    counts[index] = p.second;
                    index++;
                }

                if (counts[0] == 1 || counts[1] ==  1) {
                    // case: 1 1 1 2
                    ret = i + 1;
                } else if (abs(freqs[0] - freqs[1]) == 1) {
                    // case: 1 1 1 3 3 4 4
                    if (freqs[0] > freqs[1] && freqs[0] == counts[0])
                        ret = i + 1; 
                    else if (freqs[1] > freqs[0] && freqs[1] == counts[1])
                        ret = i + 1;
                }
            } else if (freqCount.size() == 1) {
                int freq, count;
                for (auto p : freqCount) {
                    freq = p.first;
                    count = p.second;
                }
                
                if (freq == count || freq == 1)
                    // case: 1 1 1 1 1 or 1 2 3 4 5
                    ret = i + 1;
            }
        }
        
        return ret;
    }
};