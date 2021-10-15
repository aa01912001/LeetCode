題號: 1481. Least Number of Unique Integers after K Removals

難度: Medium

## 問題描述

Given an array of integers `arr` and an integer `k`. Find the least number of unique integers after removing **exactly** `k` elements.

**Example 1:**

```
Input: arr = [5,5,4], k = 1
Output: 1
Explanation: Remove the single 4, only 5 is left.
```

**Constraints:**

- `1 <= arr.length <= 10^5`
- `1 <= arr[i] <= 10^9`
- `0 <= k <= arr.length`

---
## 解決思路

此題只要先利用`unordered_map<int, int>`將不同整數發生的頻率記錄下來後，再根據頻率去做sort，最後拋棄頻率最小的`k`個數後，利用`unordered_set<int>`算出不同的整數個數即可。


