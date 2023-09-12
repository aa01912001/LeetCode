題號: 215. Kth Largest Element in an Array
難度: Medium

## 問題描述
Given an integer array `nums` and an integer `k`, return the `kth` largest element in the array.

Note that it is the `kth` largest element in the sorted order, not the `kth` distinct element.

Can you solve it without sorting?

**Example 1:**
```
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
```

**Constraints:**

- `1 <= k <= nums.length <= 10^5`
- `-10^4 <= nums[i] <= 10^4`

## 解決思路
此題我們只需要利用min heap來儲存當前`k`的最大的元素即可，其中heap top就是當前kth largest element。若`nums[i]`大於heap top，我們就將heap top替換掉。 

最後返回heap的top元素即可。