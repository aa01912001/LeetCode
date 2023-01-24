class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if((long)m*k >　n) return -1;
        
        int i = 1, j = INT_MAX;
        while(i < j) {
            int mid = i + (j - i) / 2;
            if(checkPossible(bloomDay, m, k, mid)) {
                j = mid;
            } else {
                i = mid + 1;
            }
        }
        return j;
    }

    bool checkPossible(vector<int>& bloomDay, int m, int k, int mid) {
        int totalBouquets = 0;
        int flowerCount = 0;
        for(int i=0; i<bloomDay.size(); i++) {
            bloomDay[i] <= mid ? flowerCount++ : flowerCount = 0;
            if(flowerCount == k) {
                totalBouquets++;
                flowerCount = 0;
            }
        }

        return totalBouquets >= m;
    }
};