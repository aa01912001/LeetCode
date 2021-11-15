typedef pair<int, int> pi;

class Solution {
private:
    unordered_map<int, int> hmap; // used for dynamic programming
public:
    int getKth(int lo, int hi, int k) {
        priority_queue<pi, vector<pi>, greater<pi> > pq; // min heap
        
        for(int i=lo; i<=hi; i++) { // get the power value from lo to hi and store them into hmap
            int step = powerValue(i, 0);
            hmap[i] = step;
            pq.push({step, i});
        }
        
        int ret = 0;
        for(int i=0; i<k; i++) { // get kth item in min heap
            ret = pq.top().second;
            pq.pop();
        }
        
        return ret;
    }
    
    int powerValue(int num, int step) {
        if(num == 1) {
            return step;
        }
        
        if(hmap.find(num) != hmap.end()) {
            return hmap[num]+step;
        }
        
        if(num%2 == 0) {
            return powerValue(num/2, step+1);
        }
        
        return powerValue(num*3+1, step+1);
    }
};