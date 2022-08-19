題號: 1526. Minimum Number of Increments on Subarrays to Form a Target Array
難度: Hard

## 問題描述

You are given an integer array `target`. You have an integer array `initial` of the same size as `target` with all elements initially zeros.

In one operation you can choose **any** subarray from `initial` and increment each value by one.

Return the minimum number of operations to form a `target` *array* from `initial`.

The test cases are generated so that the answer fits in a 32-bit integer.

**Example 1:**
```
Input: target = [1,2,3,2,1]
Output: 3
Explanation: We need at least 3 operations to form the target array from the initial array.
[0,0,0,0,0] increment 1 from index 0 to 4 (inclusive).
[1,1,1,1,1] increment 1 from index 1 to 3 (inclusive).
[1,2,2,2,1] increment 1 at index 2.
[1,2,3,2,1] target array is formed.
```
**Constraints:**

- `1 <= target.length <= 10^5`
- `1 <= target[i] <= 10^5`

---
## 解決思路

此題相當於想辦法找出將`target`全減為0的最少次數，因此我們採用greedy的想法，每次判斷：

1. `target[i] > target[i-1]`： 代表`target[i]`無法隨著`targer[i-1]`遞減時降為0，必須花費額外的步驟，因此，我們將解答加上`targer[i]-targer[i-1]`。

2. `target[i] <= target[i-1]`： 代表`target[i]`可以隨著`targer[i-1]`遞減時降為0，因此該索引位置不須再花費額外步驟。