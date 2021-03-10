class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        unordered_set<int> uset;
        int i;
        for(i=0; i<A.size(); i++) {
            if(uset.find(A[i]) == uset.end()) {
                uset.insert(A[i]);
            } else {
                break;
            }
        }
        
        return A[i];
    }
};