class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        priority_queue<pair<int, int>> maxHeap;
        unordered_map<int, int> hmap;
        
        for (int code : barcodes)
            hmap[code]++;
        
        for (auto t : hmap)
            maxHeap.push({t.second, t.first});
        
        vector<int> ret;
        while (!maxHeap.empty()) {
            auto t1 = maxHeap.top(); maxHeap.pop();
            ret.push_back(t1.second);
            t1.first -= 1;
            if (!maxHeap.empty()) {
                auto t2 = maxHeap.top(); maxHeap.pop();
                ret.push_back(t2.second);
                t2.first -= 1;
                if (t2.first != 0)
                    maxHeap.push(t2);
            }
            if (t1.first != 0)
                maxHeap.push(t1);
        }
        
        return ret;
    }
};