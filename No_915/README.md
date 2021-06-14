題號: 915. Partition Array into Disjoint Intervals

難度: Medium

## 問題描述

Given an array `nums`, partition it into two (contiguous) subarrays `left` and `right` so that:

- Every element in `left` is less than or equal to every element in `right`.
- `left` and `right` are non-empty.
- `left` has the smallest possible size.

Return the **length** of `left` after such a partitioning.  It is guaranteed that such a partitioning exists.

**Example 1:**

```
Input: nums = [5,0,3,8,6]
Output: 3
Explanation: left = [5,0,3], right = [8,6]
```

Note:

1. `2 <= nums.length <= 30000`
2. `0 <= nums[i] <= 10^6`
3. It is guaranteed there is at least one way to partition `nums` as described.

---
## 解決思路

此題我們可以利用兩個`vector<int>` `leftMax`與`rightMin`，其中:

`leftMax[i]`: 紀錄`nums[0]~nums[i]`中最大的數
`rightMin[i]`: 紀錄`nums[n]~nums[i]`中最小的數

之後我們只要從0開始遍歷`leftMax`，找到`leftMax[i] <= rightMin[i+1]`，及代表此為解答的分割(代表的`nums[0]~nums[i]`的數從`index == i+1`後的位置開始皆小於等於)。之後返回i+1的長度即可。
