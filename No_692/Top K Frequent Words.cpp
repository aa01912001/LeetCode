bool comp(pair<int, string> a, pair<int, string> b) {
        if(a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    }

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(&comp)> maxQueue(comp);
        unordered_map<string, int> hmap;
        for(int i=0; i<words.size(); i++) {
            hmap[words[i]]++;
        }
        
        for(auto t : hmap) {
            pair<int, string> p = {t.second, t.first};
            maxQueue.push(p);
        }
        
        vector<string> ret;
        for(int i=1; i<=k; i++) {
            ret.push_back(maxQueue.top().second); maxQueue.pop();
        }
        
        return ret;
    }
    
};

