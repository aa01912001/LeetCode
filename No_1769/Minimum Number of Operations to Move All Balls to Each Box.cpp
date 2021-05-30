class Solution {
public:
    vector<int> minOperations(string boxes) {
        int len = boxes.length();
        vector<int> rightAccu(len, 0), leftAccu(len, 0);
        int nums = 0;
        if(boxes[0] == '1') nums++;
        for(int i=1; i<len; i++) { // calculate number of operations to move from right to left
            rightAccu[i] = rightAccu[i-1] + nums;
            if(boxes[i] == '1') nums++;
        }
        
        nums = 0;
        if(boxes[len-1] == '1') nums++;
        for(int i=len-2; i>=0; i--) { // calculate number of operations to move from left to right
            leftAccu[i] = leftAccu[i+1] + nums;
            if(boxes[i] == '1') nums++;
        }
        
        vector<int> ret(len, 0);
        for(int i=0; i<len; i++) {
            ret[i] = rightAccu[i] + leftAccu[i];
        }
        return ret;
    }
};