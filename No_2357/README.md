題號: 2357. Make Array Zero by Subtracting Equal Amounts
難度: Easy

## 問題描述
You are given a non-negative integer array `nums`. In one operation, you must:

- Choose a positive integer `x` such that `x` is less than or equal to the **smallest non-zero** element in `nums`.
- Subtract `x` from every **positive** element in `nums`.

Return the **minimum** number of operations to make every element in `nums` equal to `0`.

**Example 1:**
```
Input: nums = [1,5,0,3,5]
Output: 3
Explanation:
In the first operation, choose x = 1. Now, nums = [0,4,0,2,4].
In the second operation, choose x = 2. Now, nums = [0,2,0,0,2].
In the third operation, choose x = 2. Now, nums = [0,0,0,0,0].
```
**Constraints:**

- `1 <= nums.length <= 100`
- `0 <= nums[i] <= 100`

## 解決思路
此題首先對`nums`做遞增排序，然後從開始計算prefix sum，一旦當前的prefix sum大於陣列最後的元素(也就是最大的元素)，就代表其他元素也同樣已經被扣完了。

我們在將當前元素數字加入至prefix sum之前，要記得先扣除前一次的prefix sum值，以避免重複計算。