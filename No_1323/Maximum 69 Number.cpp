class Solution {
public:
    int maximum69Number (int num) {
        int count = 1,last = 0;
        int tmp = num;
        while(tmp > 0) {
            if(tmp % 10 == 6) {
                last = count;
            }
            count++;
            tmp /= 10;
        }
        
        return num + 3*pow(10, last-1);
    }
};