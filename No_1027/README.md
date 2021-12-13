題號: 1027. Longest Arithmetic Subsequence

難度: Medium

## 問題描述

Given an array `nums` of integers, return the **length** of the longest arithmetic subsequence in `nums`.

Recall that a subsequence of an array `nums` is a list `nums[i1], nums[i2], ..., nums[ik]` with `0 <= i1 < i2 < ... < ik <= nums.length - 1`, and that a sequence `seq` is arithmetic if `seq[i+1] - seq[i]` are all the same value (for `0 <= i < seq.length - 1`).

**Example 1:**
```
Input: nums = [20,1,15,3,10,5,8]
Output: 4
Explanation: 
The longest arithmetic subsequence is [20,15,10,5].
```

**Constraints:**

- `2 <= nums.length <= 1000`
- `0 <= nums[i] <= 500`

---
## 解決思路

此題可利用DP的策略解決，對於每個`nums[i]`，我們都假設其為**Longest Arithmetic Subsequence**的最後一個，因此必須和其前面索引位置的所有值去計算其差和找出該差值的最大序列長度，並把與前面所引位置之差值所對應的最大序列長度記錄下來，如此即可找出最大的序列長度值。

程式中我們使用`vector<unordered_map<int, int>>`的結構來儲存差值對應的最大序列長度。

