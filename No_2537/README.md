題號: 2537. Count the Number of Good Subarrays
難度: Medium

## 問題描述
Given an integer array `nums` and an integer `k`, return the number of **good** subarrays of `nums`.

A subarray `arr` is `good` if it there are **at least** `k` pairs of indices `(i, j)` such that `i < j` and `arr[i] == arr[j]`.

A **subarray** is a contiguous **non-empty** sequence of elements within an array.

**Example 1:**
```
Input: nums = [3,1,4,3,2,2,4], k = 2
Output: 4
Explanation: There are 4 different good subarrays:
- [3,1,4,3,2,2] that has 2 pairs.
- [3,1,4,3,2,2,4] that has 3 pairs.
- [1,4,3,2,2,4] that has 2 pairs.
- [4,3,2,2,4] that has 2 pairs.
```

**Constraints:**

- `1 <= nums.length <= 10^5`
- `1 <= nums[i], k <= 10^9`

---
## 解決思路
此題我們可以使用hash map來紀錄當前`nums[i]`加入或刪除後相應的pair增刪個數。另外我們透過sliding window的方式來找出所有合法的good subarray。

假設`nums[i] ~ nums[j]`的pair數大於等於`k`，那麼我們就可以確定，以下幾個子陣列的pair也必大於等於`k`:
`nums[i] ~ nums[j+1]`，`nums[i] ~ nums[j+2]` ... `nums[i] ~ nums[n]`