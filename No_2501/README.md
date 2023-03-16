題號: 2501. Longest Square Streak in an Array
難度: Medium

## 問題描述
You are given an integer array `nums`. A subsequence of `nums` is called a **square streak** if:

- The length of the subsequence is at least `2`, and
- **after** sorting the subsequence, each element (except the first element) is the **square** of the previous number.

Return the length of the **longest square streak** in `nums`, or return `-1` if there is no **square streak**.

A **subsequence** is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

**Example 1:**
```
Input: nums = [4,3,6,16,8,2]
Output: 3
Explanation: Choose the subsequence [4,16,2]. After sorting it, it becomes [2,4,16].
- 4 = 2 * 2.
- 16 = 4 * 4.
Therefore, [4,16,2] is a square streak.
It can be shown that every subsequence of length 4 is not a square streak.
```

**Constraints:**

- `2 <= nums.length <= 10^5`
- `2 <= nums[i] <= 10^5`

---
## 解決思路
此題我們先對`nums`做遞增sort，之後可以利用hash map將每個數字做為**square streak**最後數字的最長長度記錄起來。

對於每個數來說，若其根號數(假設為`num`)存在於map中，則我們紀錄當前數字map的value為`hmap[num] + 1`，否則其value為1。