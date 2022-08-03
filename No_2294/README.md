題號: 2294. Partition Array Such That Maximum Difference Is K
難度: Medium

## 問題描述

You are given an integer array `nums` and an integer `k`. You may partition `nums` into one or more **subsequences** such that each element in `nums` appears in **exactly** one of the subsequences.

Return the **minimum** number of subsequences needed such that the difference between the maximum and minimum values in each subsequence is **at most** `k`.

A **subsequence** is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

**Example 1:**
```
Input: nums = [3,6,1,2,5], k = 2
Output: 2
Explanation:
We can partition nums into the two subsequences [3,1,2] and [6,5].
The difference between the maximum and minimum value in the first subsequence is 3 - 1 = 2.
The difference between the maximum and minimum value in the second subsequence is 6 - 5 = 1.
Since two subsequences were created, we return 2. It can be shown that 2 is the minimum number of subsequences needed.
```
**Constraints:**

- `1 <= nums.length <= 10^5`
- `0 <= nums[i] <= 10^5`
- `0 <= k <= 10^5`

---
## 解決思路

此題我們可以觀察出，讓`nums`中越靠近的數為一組，即可得到較小的差值，因此，我們可以採用greedy策略先對`nums`做遞增排序後，在將`nums`從頭開始做切分，一但我們發現`nums[i]`減去當前數組最小值之差大於`k`時，代表應該開始劃分下一個數組，因此，我們將解答值加1並讓下一個數組之最小值為`nums[i]`。
