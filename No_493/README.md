題號: 493. Reverse Pairs

難度: Hard

## 問題描述

Given an integer array `nums`, return the number of **reverse pairs** in the array.

A reverse pair is a pair `(i, j)` where `0 <= i < j < nums.length` and `nums[i] > 2 * nums[j]`.

Example 1:

```
Input: nums = [1,3,2,3,1]
Output: 2
```

Constraints:

- `1 <= nums.length <= 5 * 10^4`
- `2^31 <= nums[i] <= 2^31 - 1`



---
## 解決思路

此題可用`mergeSort`將此陣列分為左子陣列與右子陣列，在合併的時候因為兩個子陣列已經是sorted的狀態，所以可以很快地找到跨兩個子陣列的**reverse pairs**，結束mergeSort即可得到所有的**reverse pairs**。
