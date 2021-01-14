class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int odd = -1, even = -2;
        int size = A.size();
        while(odd < size && even < size) {
            odd += 2;
            while(odd < size) { // find even number in odd position
                if(A[odd]%2 == 0 && odd%2 == 1) {
                    break;
                }
                odd += 2;
            }
            even += 2;
            while(even < size) { // find odd number in even position
                if(A[even]%2 == 1 && even%2 == 0) {
                    break;
                }
                even += 2;
            }
            if(odd < size && even < size) {
                int t = A[odd];
                A[odd] = A[even];
                A[even] = t;    
            }else {
                break;
            }
            
        }
        
        return A;
    }
};