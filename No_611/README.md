題號: 611. Valid Triangle Number

難度: Medium

## 問題描述

Given an integer array `nums`, return the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.


**Example 1:**

```
Input: nums = [2,2,3,4]
Output: 3
Explanation: Valid combinations are: 
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3
```

**Constraints:**

- `1 <= nums.length <= 1000`
- `0 <= nums[i] <= 1000`

---
## 解決思路

一個合法的三角形邊就是任兩邊之和大於第三邊的`triplet`，所以此題我們可以將`nums`做遞增排序後，再將`nums[k]`由後往前的判斷`nums[i]+nums[j]`是否大於`nums[k]`其中:

k : 由n-1到2遞減
i : 從0開始往後遞增
j : 從k-1往前遞減

過程中若發現`nums[i] + nums[j] > nums[k]`則將解答加上`j-i`(因為`nums`已經排序過，所以:
`nums[i] + nums[j]`、
`nums[i+1] + nums[j]`、
.
.
.
`nums[j-1] + nums[j]`皆可大於`nums[k]`)，之後再將j遞減1;
若發現`nums[i] + nums[j] <= nums[k]`，代表數字不夠大，則將i遞增1。

最後當i與j相遇後，即可找出所有的可能解。

