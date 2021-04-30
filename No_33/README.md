題號: 33. Search in Rotated Sorted Array

難度: Medium

## 問題描述

There is an integer array `nums` sorted in ascending order (with **distinct** values).

Prior to being passed to your function, `nums` is **rotated** at an unknown pivot index `k` (`0 <= k < nums.length`) such that the resulting array is `[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]` (**0-indexed**). For example, `[0,1,2,4,5,6,7]` might be rotated at pivot index `3` and become `[4,5,6,7,0,1,2]`.

Given the array `nums` **after** the rotation and an integer `target`, return the index of `target` if it is in `nums`, or `-1` if it is not in `nums`.

Example 1:

```
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
```

Constraints:

- `1 <= nums.length <= 5000`
- `-10^4 <= nums[i] <= 10^4`
- All values of `nums` are **unique**.
- `nums` is guaranteed to be rotated at some pivot.
- `-10^4 <= target <= 10^4`

**Follow up:** Can you achieve this in `O(log n)` time complexity?

---
## 解決思路

此題透過**binary search**的方式每次都選擇一個中間點`mid`，之後可以分成兩個cases:

**case 1:** nums[i] ~ nums[mid]的子陣列是遞增排序的，那麼我們檢查target是否位於於此範圍內，若是則`j = mid - 1;`，否則`i = mid + 1;`。

**case 2:** nums[mid+1] ~ nums[j]的子陣列是遞增排序的，那麼我們檢查target是否位於於此範圍內，若是則`i = mid + 1;`，否則`j = mid - 1;`。
