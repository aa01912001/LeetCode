題號: 2592. Maximize Greatness of an Array

難度: Medium

## 問題描述
## Problem Description

You are given a 0-indexed integer array `nums`. You are allowed to permute `nums` into a new array `perm` of your choosing.

We define the **greatness** of `nums` be the number of indices `0 <= i < nums.length` for which `perm[i] > nums[i]`.

Return the *maximum possible greatness you can achieve after permuting* `nums`.



**Example 1:**
```
Input: nums = [1,3,5,2,1,3,1]
Output: 4
Explanation: One of the optimal rearrangements is perm = [2,5,1,3,3,1,1].
At indices = 0, 1, 3, and 4, perm[i] > nums[i]. Hence, we return 4.
```

**Constraints:**

- `1 <= nums.length <= 10^5`
- `0 <= nums[i] <= 10^9`

**解決思路:**

此題我們先對`nums`進行遞增排序，並且初始化一個索引指標`cur`，代表經過`permute`操作後可滿足`greatness`的元素。

我們從索引1開始進行遍歷，如果`nums[i] > nums[cur]`，代表經過`permute`操作後`nums[i]`這個元素被放到`nums[cur]`這個元素的位置上，一定可滿足greatness，則我們將cur向後遞進一個位置。最後返回`cur`即為最大可能的greatness數量。