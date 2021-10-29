題號: 982. Triples with Bitwise AND Equal To Zero

難度: Hard

## 問題描述

Given an integer array nums, return the number of **AND triples**.

An **AND triple** is a triple of indices `(i, j, k)` such that:

- `0 <= i < nums.length`
- `0 <= j < nums.length`
- `0 <= k < nums.length`
- `nums[i] & nums[j] & nums[k] == 0`, where `&` represents the bitwise-AND operator.

**Example 1:**

```
Input: nums = [2,1,3]
Output: 12
Explanation: We could choose the following i, j, k triples:
(i=0, j=0, k=1) : 2 & 2 & 1
(i=0, j=1, k=0) : 2 & 1 & 2
(i=0, j=1, k=1) : 2 & 1 & 1
(i=0, j=1, k=2) : 2 & 1 & 3
(i=0, j=2, k=1) : 2 & 3 & 1
(i=1, j=0, k=0) : 1 & 2 & 2
(i=1, j=0, k=1) : 1 & 2 & 1
(i=1, j=0, k=2) : 1 & 2 & 3
(i=1, j=1, k=0) : 1 & 1 & 2
(i=1, j=2, k=0) : 1 & 3 & 2
(i=2, j=0, k=1) : 3 & 2 & 1
(i=2, j=1, k=0) : 3 & 1 & 2
```

**Constraints:**

- `1 <= nums.length <= 1000`
- `0 <= nums[i] < 2^16`

---
## 解決思路

此題我們可以利用`unordered_map<int, int>`來儲存`nums`中所有pair做`AND`運算後的值，之後再將map中的所有pair值與`nums`中的所有數一一去做`AND`運算來判斷是否為0即可。若為0則將該pair值的個數加至解答上，代表最後一個位置為當前`nums`中的數的索引可能形成的triple個數。







