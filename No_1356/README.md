題號: 1356. Sort Integers by The Number of 1 Bits

難度: Easy

## 問題描述

Given an integer array `arr`. You have to sort the integers in the array in ascending order by the number of **1's** in their binary representation and in case of two or more integers have the same number of **1's** you have to sort them in ascending order.

Return the sorted array.

Example 1:

```
Input: arr = [0,1,2,3,4,5,6,7,8]
Output: [0,1,2,4,8,3,5,6,7]
Explantion: [0] is the only integer with 0 bits.
[1,2,4,8] all have 1 bit.
[3,5,6] have 2 bits.
[7] has 3 bits.
The sorted array by bits is [0,1,2,4,8,3,5,6,7]
```

Constraints:

- `1 <= arr.length <= 500`
- `0 <= arr[i] <= 10^4`



---
## 解決思路

此題我們只要使用sort()，並且客製化comparator去做比較即可。