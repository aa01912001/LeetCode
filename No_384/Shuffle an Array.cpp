class Solution {
private:
    vector<int> origin;
public:
    Solution(vector<int>& nums) {
        origin = nums;
    }
    
    vector<int> reset() {
        return origin;
    }
    
    vector<int> shuffle() {
        int size = origin.size();
        vector<int> index(size); // keep the index from 0 to (array size - 1)
        for(int i=0; i<size; i++) {
            index[i] = i;
        }
        
        int decreSize = size;
        vector<int> shuffleArray(size); // shuffled array
        for(int i=0; i<size; i++) { // random a new position for origin[i]
            int r = rand()%decreSize;
            decreSize--;
            shuffleArray[index[r]] = origin[i];
            int t = index[r];
            index[r] = index[decreSize];
            index[decreSize] = t;
        }
        
        return shuffleArray;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */