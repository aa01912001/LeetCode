題號: 852. Peak Index in a Mountain Array
難度: Easy

## 問題描述

Let's call an array `arr` a **mountain** if the following properties hold:

- `arr.length >= 3`
- There exists some `i` with `0 < i < arr.length - 1` such that:
    - `arr[0] < arr[1] < ... arr[i-1] < arr[i]`
    - `arr[i] > arr[i+1] > ... > arr[arr.length - 1]`

Given an integer array `arr` that is **guaranteed** to be a mountain, return any `i` such that `arr[0] < arr[1] < ... arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1]`.

**Example 1:**
```
Input: arr = [0,1,0]
Output: 1
```
**Constraints:**

- `3 <= arr.length <= 10^4`
- `0 <= arr[i] <= 10^6`
- `arr` is **guaranteed** to be a mountain array.

---
## 解決思路

此題只需要binary search找出同時大於左邊與右邊的位置即可。