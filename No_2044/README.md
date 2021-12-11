題號: 2044. Count Number of Maximum Bitwise-OR Subsets

難度: Medium

## 問題描述

Given an integer array `nums`, find the **maximum** possible **bitwise OR** of a subset of `nums` and return the **number of different non-empty subsets** with the maximum bitwise OR.

An array `a` is a **subset** of an array `b` if `a` can be obtained from `b` by deleting some (possibly zero) elements of `b`. Two subsets are considered **different** if the indices of the elements chosen are different.

The bitwise OR of an array `a` is equal to `a[0] OR a[1] OR ... OR a[a.length - 1]` (**0-indexed**).

**Example 1:**
```
Input: nums = [3,1]
Output: 2
Explanation: The maximum possible bitwise OR of a subset is 3. There are 2 subsets with a bitwise OR of 3:
- [3]
- [3,1]
```

**Constraints:**

- `1 <= nums.length <= 16`
- `1 <= nums[i] <= 10^5`

---
## 解決思路

此題可使用只需要DFS策略將所有subset的OR值記錄下來後，在取出最大OR的個數。

程式中我們用`unordered_map<int, int>`來記錄個OR值有多少個subset。

在DFS中我們每當遍歷一個索引位置後，就必須考慮此位置包含與不包含進subset的情形來進行進一步的DFS(也就是要不要將此位置的值與當前暫存的OR做OR運算)。

