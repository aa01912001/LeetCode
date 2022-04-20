題號: 2206. Divide Array Into Equal Pairs
難度: Easy

## 問題描述

You are given an integer array `nums` consisting of `2 * n` integers.

You need to divide `nums` into `n` pairs such that:

- Each element belongs to **exactly one** pair.
- The elements present in a pair are **equal**.

Return `true` if nums can be divided into `n` pairs, otherwise return `false`.

**Example 1:**
```
Input: nums = [3,2,3,2,2,2]
Output: true
Explanation: 
There are 6 elements in nums, so they should be divided into 6 / 2 = 3 pairs.
If nums is divided into the pairs (2, 2), (3, 3), and (2, 2), it will satisfy all the conditions.
```

**Constraints:**

- `nums.length == 2 * n`
- `1 <= n <= 500`
- `1 <= nums[i] <= 500`

---
## 解決思路

此題我們此需要統計`nums`每個數的出現次數是否皆為偶數即可(因為pair存放兩數，所以每個數應該要剛好能被2整除)。

