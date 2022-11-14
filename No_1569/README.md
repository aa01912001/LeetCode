題號: 1569. Number of Ways to Reorder Array to Get Same BST
難度: Hard

## 問題描述

Given an array `nums` that represents a permutation of integers from `1` to `n`. We are going to construct a binary search tree (BST) by inserting the elements of `nums` in order into an initially empty BST. Find the number of different ways to reorder `nums` so that the constructed BST is identical to that formed from the original array `nums`.

- For example, given `nums = [2,1,3]`, we will have 2 as the root, 1 as a left child, and 3 as a right child. The array `[2,3,1]` also yields the same BST but `[3,2,1]` yields a different BST.

Return the number of ways to reorder `nums` such that the BST formed is identical to the original BST formed from `nums`.

Since the answer may be very large, **return it modulo** `10^9 + 7`.

**Example 1:**
![image alt](https://assets.leetcode.com/uploads/2020/08/12/ex1.png)
```
Input: nums = [3,4,5,1,2]
Output: 5
Explanation: The following 5 arrays will yield the same BST: 
[3,1,2,4,5]
[3,1,4,2,5]
[3,1,4,5,2]
[3,4,1,2,5]
[3,4,1,5,2]
```

**Constraints:**

- `1 <= nums.length <= 1000`
- `1 <= nums[i] <= nums.length`
- All integers in `nums` are **distinct**.

---
## 解決思路

此題假設我們有一陣列`nums`，我們可以知道root必定是`nums[0]`，我們可以採用divide and conquer的方式將`nums[1]~nums[n]`分成小於與大於`nums[0]`的兩堆(分別按索引順序存為`less`，與`greater`)。

假設`nums`如下:

`[r, l_1, g_1, l_2, l_3, g_2, ... , l_n1, ... g_n2]`，其中`l_1` ~ `l_n1`為小於`r`之元素，`g_1` ~ `g_n2`為大於`r`之元素。

因為左右子樹的插入互不影響，因此只要`l_1` ~ `l_n1`與`g_1` ~ `g_n2`在`nums`中各自的內部順序不改變，就可以得到與`nums`相同的BST。

因此，我們只需要各自解出`less`(左子樹)與`greater`(右子樹)的解答值，相乘並再乘上`l_1, g_1, l_2, l_3, g_2, ... , l_n1, ... g_n2`不影響左右子樹內部次序的排列總數後，即為最終解答。