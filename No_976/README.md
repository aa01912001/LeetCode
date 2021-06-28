題號: 976. Largest Perimeter Triangle

難度: Easy

## 問題描述

Given an integer array `nums`, return the largest perimeter of a triangle with a non-zero area, formed from three of these lengths. If it is impossible to form any triangle of a non-zero area, return `0`.


**Example 1:**

```
Input: nums = [3,2,3,4]
Output: 10
```

**Constraints:**

- `3 <= nums.length <= 10^4`
- `1 <= nums[i] <= 10^6`


---
## 解決思路

一個合法的三角形邊就是任兩邊之和大於第三邊的`triplet`，所以此題我們可以將`nums`做遞增排序後，再將`nums[k]`由後往前的判斷`nums[i]+nums[j]`是否大於`nums[k]`其中:

k : 由n-1到2遞減
i : 從0開始往後遞增
j : 從k-1往前遞減

過程中若發現`nums[i] + nums[j] > nums[k]`則返回`nums[j-1]+nums[j]+nums[k]`(因為`nums`為遞增排序，所以`nums[j-1]、nums[j]、nums[k]`一定也滿足三角形邊長規則，且為最大周長)。
若發現`nums[i] + nums[j] <= nums[k]`，代表數字不夠大，則將i遞增1。

最後當i與j相遇，則代表，`nums[k]`太大，所以應該將k的索引值遞減1。

