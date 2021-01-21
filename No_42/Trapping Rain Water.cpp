class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        if(size == 0) return 0;
        int maxL = height[0];
        int maxR = height[size-1];
        int leftMax[size]; // store the maximum left height
        int rightMax[size]; // store the maximum right height
        
        for(int i=0; i<size; i++) { 
            if(maxL < height[i]) {
                maxL = height[i];
            }
            leftMax[i] = maxL;
        }
        
        for(int i=size-1; i>=0; i--) {
            if(maxR < height[i]) {
                maxR = height[i];
            }
            rightMax[i] = maxR;
        }
        
        int ret = 0;
        for(int i=0; i<size; i++) {
            ret += min(leftMax[i], rightMax[i]) - height[i]; // how much water this section can trap
        }
        return ret;
    }
};