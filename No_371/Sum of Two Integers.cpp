class Solution {
public:
    int getSum(int a, int b) {
        unsigned int carry = a & b;
        int sum = a ^ b ;
        carry <<= 1;
        while(carry != 0) {
            int pre_carry = carry;
            carry = carry & sum;
            sum = pre_carry ^ sum;
            carry <<= 1;
        }
        
        return sum;
    }
};