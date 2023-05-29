class Solution {
public:
    bool isPossible(vector<int>& target) {
        int n = target.size();
        long long sum = 0;
        if (n == 1) return target[0] == 1;
        priority_queue<int> pq;
        for (int num : target) {
            pq.push(num);
            sum += num;
        }

        while (sum > n) {
            int t = pq.top(); pq.pop();
            long long remain = sum - t;
            if (t - remain < 1) return false;
            
            // try to decrease the number of iteration
            int minus = (t - 1) / remain * remain;
            t -= minus;
            sum -= minus;
            pq.push(t);
        }
        
        return true;
    }
};