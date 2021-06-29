class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> umap;
        for(int i=0; i<arr1.size(); i++) {
            umap[arr1[i]]++;
        }
        
        int index = 0;
        for(int i=0; i<arr2.size(); i++) {
            int num = arr2[i];
            while(umap[num]--) {
                arr1[index] = num;
                index++;
            }
        }
        
        for(auto &t : umap) {
            if(t.second == -1) continue;
            while(t.second--) {
                arr1[index] = t.first;
                index++;
            }
        }
        
        return arr1;
    }
};