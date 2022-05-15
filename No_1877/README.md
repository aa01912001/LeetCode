題號: 1877. Minimize Maximum Pair Sum in Array
難度: Medium

## 問題描述

The **pair sum** of a pair `(a,b)` is equal to `a + b`. The **maximum pair sum** is the largest **pair sum** in a list of pairs.

- For example, if we have pairs `(1,5)`, `(2,3)`, and `(4,4)`, the **maximum pair sum** would be `max(1+5, 2+3, 4+4) = max(6, 5, 8) = 8`.

Given an array `nums` of **even** length `n`, pair up the elements of `nums` into `n / 2` pairs such that:

- Each element of `nums` is in **exactly one** pair, and
- The **maximum pair sum** is **minimized**.

Return the minimized **maximum pair sum** after optimally pairing up the elements.

**Example 1:**
```
Input: nums = [3,5,2,3]
Output: 7
Explanation: The elements can be paired up into pairs (3,3) and (5,2).
The maximum pair sum is max(3+3, 5+2) = max(6, 7) = 7.
```
**Constraints:**

- `n == nums.length`
- `2 <= n <= 10^5`
- `n` is **even**.
- `1 <= nums[i] <= 10^5`

---
## 解決思路

要將array中**maximum pair sum**盡可能降低的想法在於我們應該把越大的數配對給盡可能小的數，因此，此題我們可以先將`nums`做sorting後，再依序將頭尾兩兩配對，過程中我們要記錄最大的那個pair sum，並於最後返回該值即可。