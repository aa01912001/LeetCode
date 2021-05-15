題號: 1822. Sign of the Product of an Array

難度: Easy

## 問題描述

There is a function `signFunc(x)` that returns:

- `1` if `x` is positive.
- `-1` if `x` is negative.
- `0` if `x` is equal to `0`.

You are given an integer array `nums`. Let `product` be the product of all values in the array `nums`.

Return `signFunc(product)`.

Example 1:

```
Input: nums = [-1,-2,-3,-4,3,2,1]
Output: 1
Explanation: The product of all values in the array is 144, and signFunc(144) = 1
```

Constraints:

- `1 <= nums.length <= 1000`
- `-100 <= nums[i] <= 100`


---
## 解決思路

此題只需要將`nums`遍歷一次找出負數的個數後，在判斷出現的次數;若為偶數個則返回1，否則為-1。而遍歷過程中只要有出現0則返回0。

