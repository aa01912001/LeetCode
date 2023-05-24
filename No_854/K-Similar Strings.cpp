class Solution {
public:
    int kSimilarity(string A, string B) {
        queue<string> q{{A}};
        unordered_set<string> hset{{A}};
        int ret = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size-- != 0) {
                string cur = q.front(); q.pop();
                if (cur == B) return ret;
                int i = 0;
                while (cur[i] == B[i]) i++;
                for (int j=i+1; j<cur.length(); j++) {
                    if (cur[j] == B[j] || cur[j] != B[i])
                        continue;
                    swap(cur[i], cur[j]);
                    if (hset.find(cur) == hset.end()) {
                        hset.insert(cur);
                        q.push(cur);
                    }
                    swap(cur[i], cur[j]);
                }
            }
            ret++;
        }
        
        return -1;
    }
};