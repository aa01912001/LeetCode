題號: 1985. Find the Kth Largest Integer in the Array
難度: Medium

## 問題描述

You are given an array of strings `nums` and an integer `k`. Each string in `nums` represents an integer without leading zeros.

Return the string that represents the `kth` **largest integer** in `nums`.

**Note**: Duplicate numbers should be counted distinctly. For example, if `nums` is `["1","2","2"]`, `"2"` is the first largest integer, `"2"` is the second-largest integer, and `"1"` is the third-largest integer.

**Example 1:**

```
Input: nums = ["2","21","12","1"], k = 3
Output: "2"
Explanation:
The numbers in nums sorted in non-decreasing order are ["1","2","12","21"].
The 3rd largest integer in nums is "2".
```

**Constraints:**

- `1 <= k <= nums.length <= 10^4`
- `1 <= nums[i].length <= 100`
- `nums[i]` consists of only digits.
- `nums[i]` will not have any leading zeros.

---
## 解決思路

此題我們可利用min heap來儲存前`k`大的字串，最後返回`top`即可。

首先我們從頭開始遍歷`nums`，一旦發現`heap size < k`則無條件插入當前字串，否則當`heap size >= k`時，我們在插入當前字串後就將heap top取出，使heap的size維持在`k`，如此就能保證heap top是當前遍歷過的字串中第`k`大的。