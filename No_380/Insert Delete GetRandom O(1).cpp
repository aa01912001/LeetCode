class RandomizedSet {
private:
    unordered_map<int, int> hmap;
    vector<int> nums;
    
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(hmap.find(val) == hmap.end()) {
            hmap[val] = nums.size();
            nums.push_back(val);
            return true;
        }
        
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(hmap.find(val) != hmap.end()) {
            int valIndex = hmap[val];
            int tmp = nums.back();
            swap(nums[valIndex], nums[nums.size()-1]);
            nums.pop_back();
            hmap[tmp] = hmap[val];
            hmap.erase(val);
            return true;
        }
        
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand()%nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */