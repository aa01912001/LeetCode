題號: 3074. Apple Redistribution into Boxes

難度: `Easy`

## 問題描述

You are given an array `apple` of size `n` and an array `capacity` of size `m`.

There are `n` packs where the `ith` pack contains `apple[i]` apples. There are `m` boxes as well, and the `ith` box has a capacity of `capacity[i]` apples.

Return the **minimum** number of boxes you need to select to redistribute these `n` packs of apples into boxes.

**Note** that, apples from the same pack can be distributed into different boxes.

**Example 1:**
```
Input: apple = [1,3,2], capacity = [4,3,1,5,2]
Output: 2
Explanation: We will use boxes with capacities 4 and 5.
It is possible to distribute the apples as the total capacity is greater than or equal to the total number of apples.
```
**Constraints:**

- `1 <= n == apple.length <= 50`
- `1 <= m == capacity.length <= 50`
- `1 <= apple[i], capacity[i] <= 50`
- The input is generated such that it's possible to redistribute packs of apples into boxes.

**解決思路:**

此題單純優先從capacity大的盒子開始裝就好。