題號: 992. Subarrays with K Different Integers
難度: Hard

## 問題描述

Given an integer array `nums` and an integer `k`, return the number of **good subarrays** of `nums`.

A **good array** is an array where the number of different integers in that array is exactly `k`.

- For example, `[1,2,3,1,2]` has `3` different integers: `1`, `2`, and `3`.

A **subarray** is a **contiguous** part of an array.

**Example 1:**
```
Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]
```

**Constraints:**

- `1 <= nums.length <= 2 * 10^4`
- `1 <= nums[i], k <= nums.length`

---
## 解決思路

此題要找出剛好為k個不同整數的子陣列數量非常困難，因此，我們可以將題目轉換為找出最多k個不同整數的子陣列數量。

因此我們可以知道:

(最多k個不同整數的子陣列數量) - (最多k-1個不同整數的子陣列數量) = (剛好為k個不同整數的子陣列數量)

而針對找尋最多k個不同整數的子陣列數量之方法，我們可以使用**sliding window**的方式來解決，我們使`left`為滿足條件(不同整數數量 <= k)的左邊界，而`i`為向右成長之子陣列尾端，當我們發現當前整數個數小於等於`k`，則`i - left + 1`為當前的可能子陣列個數，一旦當前整數個數大於`k`，我們則使`left`向右移動直到等於`k`即可。