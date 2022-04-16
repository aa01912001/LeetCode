class Solution {
private:
    vector<int> wSum;
public:
    Solution(vector<int>& w) {
        int sum = 0;
        for(int i=0; i<w.size(); i++) {
            sum += w[i];
            wSum.push_back(sum);
        }
        srand(time(nullptr));
    }
    
    int pickIndex() {
        int target = rand() % wSum.back() + 1;
        int left = 0, right = wSum.size() - 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(wSum[mid] == target) {
                return mid;
            } else if(wSum[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return right;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */