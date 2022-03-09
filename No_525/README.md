題號: 525. Contiguous Array
難度: Medium

## 問題描述

Given a binary array `nums`, return the maximum length of a contiguous subarray with an equal number of `0` and `1`.

**Example 1:**
```
Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
```

**Constraints:**

- `1 <= nums.length <= 10^5`
- `nums[i]` is either `0` or `1`.

---
## 解決思路

此題我們可使用prefix sum的技巧，準備一個變數`sum`，當遍歷`nums`的過程中，遇到1即+1，反之0為-1，因此，透過`sum`可以得知當前0與1個數的差值，一但後續同樣的`sum`值又出現，代表此次`sum`值與第一次`sum`值之間的0與1個數是同樣多的；在程式中，我們使用`unordered_map<int, int>`來儲存不同`sum`值間所對應第一次出現的索引值。

Note: 由於我們所要求的是在同樣的`sum`值出現時，兩者間的最大值，因此，map中只存放第一次差值出現時所對應的索引值。

