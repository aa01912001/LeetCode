題號: 1424. Diagonal Traverse II
難度: Medium

## 問題描述

Given a 2D integer array `nums`, return all elements of `nums` in diagonal order as shown in the below images.

**Example 1:**
![image alt](https://assets.leetcode.com/uploads/2020/04/08/sample_2_1784.png)
```
Input: nums = [[1,2,3,4,5],[6,7],[8],[9,10,11],[12,13,14,15,16]]
Output: [1,6,2,8,7,3,9,4,12,10,5,13,11,14,15,16]
```

**Constraints:**

- `1 <= nums.length <= 10^5`
- `1 <= nums[i].length <= 10^5`
- `1 <= sum(nums[i].length) <= 10^5`
- `1 <= nums[i][j] <= 10^5`

---
## 解決思路

此題藉由觀察矩陣我們可以發現相同對角的元素其`row + col`會相等，相同對角中的元素，其`col`值會大於前一個相同對角中的元素，因此藉由min heap我們可以將`nums`中的所有元素依據`{row+col, col, nums[row][col]}`屬性放入其中，之後只要依序從min heap取出即可(將`nums[row][col]`放入解答中)。


