class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int ret = 0;
        while(left < right) {
            ret = max(ret, (right-left)*min(height[left], height[right]));
            if(height[left] <= height[right])
                left++;
            else
                right--;
        }
        return ret;
    }
};