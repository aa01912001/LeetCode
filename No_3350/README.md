題號: 3350. Adjacent Increasing Subarrays Detection II

難度: Medium

## 問題描述
## Problem Description

Given an array `nums` of `n` integers, your task is to find the **maximum value of `k`** for which there exist **two adjacent subarrays** of length `k` each, such that both subarrays are **strictly increasing**.

Specifically, check if there are two subarrays of length `k` starting at indices `a` and `b` (`a < b`), where:

- Both subarrays `nums[a..a + k − 1]` and `nums[b..b + k − 1]` are strictly increasing.
- The subarrays must be adjacent, meaning `b = a + k`.

Return the **maximum possible value** of `k`.

A **subarray** is a contiguous **non-empty** sequence of elements within an array.



**Example 1:**
```
Input: nums = [2,5,7,8,9,2,3,4,3,1]

Output: 3

Explanation:

    The subarray starting at index 2 is [7, 8, 9], which is strictly increasing.
    The subarray starting at index 5 is [2, 3, 4], which is also strictly increasing.
    These two subarrays are adjacent, and 3 is the maximum possible value of k for which two such adjacent strictly increasing subarrays exist.
```

**Constraints:**

- `2 <= nums.length <= 2 * 10^5`
- `-10^9 <= nums[i] <= 10^9`

**解決思路:**

對於遞增區間長度為 `L`，我們可以貢獻的 `k = L // 2`
但如果遞增區間被中斷，我們也可以檢查前一段與當前段能否組成相鄰對，例如：
`[1,2,3,1,2,3,4]`
上一段長度3, 下一段長度4 → 相鄰 → k = min(3,4)

因此我們可以依序遍歷`nums`來記錄每一段嚴格遞增子陣列的長度為`curr_len`，迭代時分為兩種cases:

1. `nums[i] > nums[i-1]`:
則我們將`curr_len += 1`
    
2. `nums[i] <= nums[i-1]`:
代表遞增中止了，我們更新解答值為:
`ans = max(ans, curr_len // 2)`。
另外需要考慮到上一段的子陣列長度，並與當前長度比較後做更新:
`ans = max(ans, min(prev_len, curr_len))`
最後更新前一段長度:
`prev_len = curr_len`