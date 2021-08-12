題號: 1848. Minimum Distance to the Target Element

難度: Easy

## 問題描述

Given an integer array `nums` (**0-indexed**) and two integers `target` and `start`, find an index `i` such that `nums[i] == target` and `abs(i - start)` is **minimized**. Note that `abs(x)` is the absolute value of x.

Return `abs(i - start)`.

It is **guaranteed** that `target` exists in `nums`.

**Example 1:**

```
Input: nums = [1,2,3,4,5], target = 5, start = 3
Output: 1
Explanation: nums[4] = 5 is the only value equal to target, so the answer is abs(4 - 3) = 1.
```

**Constraints:**

- `1 <= nums.length <= 1000`
- `1 <= nums[i] <= 10^4`
- `0 <= start < nums.length`
- `target` is in `nums`.


---
## 解決思路

此題只要從`start`的位置開始向左與向右尋找`target`後，再返回兩方向最短的距離即可。


