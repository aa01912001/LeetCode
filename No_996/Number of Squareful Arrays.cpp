class Solution {
public:
    int numSquarefulPerms(vector<int>& nums) {
        return permutation(nums, 0, -1);
    }
    
    int permutation(vector<int>& nums, int index, int preNum) {

        if(index == nums.size()-1 && isSquare(preNum + nums[index])) {
           return 1;
        }
        
        unordered_set<int> hset;
        int ret = 0;
        for(int i=index; i<nums.size(); i++) {
            if(hset.find(nums[i]) == hset.end()) { // in case of duplicate permutation
                hset.insert(nums[i]);
                if(preNum != -1 && !isSquare(preNum+nums[i])) continue; // backtracking
                swap(nums, index, i);
                ret += permutation(nums, index+1, nums[index]);
                swap(nums, index, i);
                
            }
        }
        
        return ret;
    }
    
    void swap(vector<int>& nums, int i, int j) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
        return;
    }
    
    bool isSquare(int num) {
        float root = sqrt(num);
        return root == (int)root; 
    }
};