題號: 941. Valid Mountain Array

難度: Easy

## 問題描述

Given an array of integers `arr`, return `true` if and only if it is a valid mountain array.

Recall that arr is a mountain array if and only if: 

- `arr.length >= 3`
- There exists some `i` with `0 < i < arr.length - 1` such that:
    - `arr[0] < arr[1] < ... < arr[i - 1] < arr[i]`
    - `arr[i] > arr[i + 1] > ... > arr[arr.length - 1]`

![image alt](https://assets.leetcode.com/uploads/2019/10/20/hint_valid_mountain_array.png)


**Example 1:**

```
Input: arr = [0,3,2,1]
Output: true
```

**Constraints:**

- `1 <= arr.length <= 10^4`
- `0 <= arr[i] <= 10^4`

---
## 解決思路

此題我們只要利用兩個指標，分別從陣列左右兩邊找出嚴格遞增的最後一個位置是否相同即可。









