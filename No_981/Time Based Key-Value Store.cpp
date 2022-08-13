class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> hmap;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        hmap[key].push_back({timestamp, value});
        return;
    }
    
    string get(string key, int timestamp) {
        if(hmap.find(key) == hmap.end()) return "";
        if(timestamp < hmap[key][0].first) return "";
        
        int start = 0, end = hmap[key].size() - 1;
        while(start < end) {
            int mid = start + (end - start) / 2;
            if(hmap[key][mid].first == timestamp) {
                return hmap[key][mid].second;
            } else if(hmap[key][mid].first > timestamp) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        
        if(hmap[key][start].first > timestamp) {
            return  hmap[key][start-1].second;
        }
        return hmap[key][start].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */