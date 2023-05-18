class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if (a != 0) pq.push({a, 'a'});
        if (b != 0) pq.push({b, 'b'});
        if (c != 0) pq.push({c, 'c'});
        
        string ret = "";
        while (!pq.empty()) {
            auto p = pq.top(); pq.pop();
            int len = ret.length();
            if (len >= 2 && p.second == ret[len-1] && p.second == ret[len-2]) {
                if (pq.empty()) {
                    break;
                } else {
                    auto p2 = pq.top(); pq.pop();
                    ret += p2.second;
                    p2.first -= 1;
                    if (p2.first != 0) pq.push(p2);
                    pq.push(p);
                    continue;
                }
            }
            ret += p.second;
            p.first -= 1;
            if (p.first != 0) pq.push(p);
        }
    
        return ret;
    }
};