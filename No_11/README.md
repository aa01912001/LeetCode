題號: 11. Container With Most Water
難度: Medium

## 問題描述

You are given an integer array `height` of length `n`. There are `n` vertical lines drawn such that the two endpoints of the `ith` line are `(i, 0)` and `(i, height[i])`.

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

**Notice** that you may not slant the container.

**Example 1:**
![image alt](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/17/question_11.jpg)
```
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
```
**Constraints:**

- `n == height.length`
- `2 <= n <= 10^5`
- `0 <= height[i] <= 10^4`

---
## 解決思路

此題我們只需要利用two pointers分別從最左及最右向內縮即可，每一次我們計算出當前容量後就去與當前解答值比較並更新，之後將高度較小的位置向內前進一步即可。
