class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for(int i=0; i<piles.size(); i++) {
            pq.push(piles[i]);
        }
        
        while(k--) {
            int t = pq.top();
            pq.pop();
            t = (t/2.) + 0.5;
            pq.push(t);
        }
        
        int ret = 0;
        while(!pq.empty()) {
            ret += pq.top();
            pq.pop();
        }
        
        return ret;
    }
};