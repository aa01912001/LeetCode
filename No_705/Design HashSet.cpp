class MyHashSet {
private:
    vector<bool> setArray;
public:
    MyHashSet() {
        setArray = vector<bool>(1000001, false);
    }
    
    void add(int key) {
        setArray[key] = true;
    }
    
    void remove(int key) {
        setArray[key] = false;
    }
    
    bool contains(int key) {
        return setArray[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */