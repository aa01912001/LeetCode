題號: 46. Permutations
難度: Medium

## 問題描述
Given an array `nums` of distinct integers, return all the possible permutations. You can return the answer in **any order**.

**Example 1:**
```
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
```

**Constraints:**

- `1 <= nums.length <= 6`
- `-10 <= nums[i] <= 10`
- All the integers of `nums` are **unique**.

## 解決思路
此題我們透過**backtracking**的方式，不斷將`index`的索引位置與後續的位置做交換後，再繼續遞迴下去，直到`index`的值等於`nums.size()`，我們就將當前的`nums`放入解答中後返回。