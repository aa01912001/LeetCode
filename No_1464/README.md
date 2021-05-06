題號: 1464. Maximum Product of Two Elements in an Array

難度: Easy

## 問題描述

Given the array of integers `nums`, you will choose two different indices `i` and `j` of that array. Return the maximum value of `(nums[i]-1)*(nums[j]-1)`.


Example 1:

```
Input: nums = [3,4,5,2]
Output: 12 
Explanation: If you choose the indices i=1 and j=2 (indexed from 0), you will get the maximum value, that is, (nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4 = 12. 
```

Constraints:

- `2 <= nums.length <= 500`
- `1 <= nums[i] <= 10^3`



---
## 解決思路

此題只要用一層for迴圈來找出`nums`中前兩大的數字x、y後再返回(x-1)\*(y-1)即可。

