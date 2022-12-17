class LRUCache {
private:
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int>>::iterator> hmap;
    int size;
public:
    LRUCache(int capacity) {
        size = capacity;
        l.clear();
        hmap.clear();
    }
    
    int get(int key) {
        if(hmap.find(key) != hmap.end()) {
            // key is existed
            list<pair<int, int>>::iterator target = hmap[key];
            l.splice(l.begin(), l, target);
            return l.begin()->second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(hmap.find(key) != hmap.end()) {
            // key is existed
            list<pair<int, int>>::iterator target = hmap[key];
            target->second = value;
            l.splice(l.begin(), l, target);
        } else {
            if(size == 0) {
                // cache is full
                pair<int, int> last = l.back();
                l.pop_back();
                hmap.erase(last.first);
                l.push_front({key, value});
            } else {
                l.push_front({key, value});
                size--;
            }
        }
        hmap[key] = l.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */