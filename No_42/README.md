題號: 42. Trapping Rain Water

難度: Hard

## 問題描述
Given `n` non-negative integers representing an elevation map where the width of each bar is `1`, compute how much water it can trap after raining.

Example 1:
![image alt](https://assets.leetcode.com/uploads/2018/10/22/rainwatertrap.png)
```
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
```

Constraints:

- `n == height.length`
- `0 <= n <= 3 * 104`
- `0 <= height[i] <= 105`

---
## 解決思路
此題利用DP的方式先紀錄每個section於左側(包含自己)及右側(包含自己)的最大高度(儲存在`leftMax`與`rightMax`陣列中)。之後再遍歷每個section利用`min(leftMax[i], rightMax[i]) - height[i]`公式即可找出該section於雨天可以持有的水量。