題號: 1295. Find Numbers with Even Number of Digits

難度: Easy

## 問題描述

Given an array `nums` of integers, return how many of them contain an **even number** of digits. 

Example 1:


```
Input: nums = [12,345,2,6,7896]
Output: 2
Explanation: 
12 contains 2 digits (even number of digits). 
345 contains 3 digits (odd number of digits). 
2 contains 1 digit (odd number of digits). 
6 contains 1 digit (odd number of digits). 
7896 contains 4 digits (even number of digits). 
Therefore only 12 and 7896 contain an even number of digits.
```

Constraints:

- `1 <= nums.length <= 500`
- `1 <= nums[i] <= 10^5`


---
## 解決思路

對於`nums`中的每一個數，只要將之一直除等於10來計算該數的digits個數即可。