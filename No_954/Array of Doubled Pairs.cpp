class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> hmap;
        for(int i=0; i<arr.size(); i++) {
            hmap[arr[i]]++;
        }
        
        sort(arr.begin(), arr.end()); // pick in correct way
        
        int i=0;
        int num=0;
        while(i<arr.size()) {
            if(hmap[arr[i]] == 0) {
                i++;
            } else {
                hmap[arr[i]]--; // current number will be used
                if(hmap[2*arr[i]] <= 0) {
                    hmap[arr[i]]++; // current number did not be used
                    i++;
                    continue;
                }
                hmap[2*arr[i]]--;
                i++;
                num++;
            }
        }
        return num == arr.size()/2;
    }
};