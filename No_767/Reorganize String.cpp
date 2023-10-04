class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int, char>> maxHeap;
        unordered_map<int, int> hmap;
        string ret = "";
        
        for (char c : s) {
            hmap[c]++;
        }
        
        for (auto p : hmap) {
            maxHeap.push({p.second, p.first});
        }
        
        char pre = ' ';
        while (!maxHeap.empty()) {
            auto t1 = maxHeap.top(); maxHeap.pop();
            if (maxHeap.empty() && t1.second == pre) return "";
            ret += t1.second;
            pre = t1.second;
            
            if (!maxHeap.empty()) {
                auto t2 = maxHeap.top(); maxHeap.pop();
                ret += t2.second;
                if (--t2.first > 0) maxHeap.push(t2);
                pre = t2.second;
            }
            
            if (--t1.first > 0) maxHeap.push(t1);
        }
        
        return ret;
    }
};