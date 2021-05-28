class Solution {
public:
    vector<int> closestDivisors(int num) {
        int num1 = num + 1;
        int num2 = num + 2;
        int i = (int)sqrt(num1);
        vector<int> num1_sol(2, 0);
        while(i>=1) {
            if(num1 % i == 0) {
                num1_sol[0] = i;
                num1_sol[1] = num1/i;
                break;
            }
            i--;
        }
        
        i = (int)sqrt(num2);
        vector<int> num2_sol(2, 0);
        while(i>=1) {
            if(num2 % i == 0) {
                num2_sol[0] = i;
                num2_sol[1] = num2/i;
                break;
            }
            i--;
        }
        
        if((num1_sol[1]-num1_sol[0]) < (num2_sol[1]-num2_sol[0])) {
            return num1_sol;
        }
        return num2_sol;
    }
};