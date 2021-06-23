題號: 1720. Decode XORed Array

難度: Easy

## 問題描述

There is a **hidden** integer array `arr` that consists of n non-negative integers.

It was encoded into another integer array `encoded` of length `n - 1`, such that `encoded[i] = arr[i] XOR arr[i + 1]`. For example, if `arr = [1,0,2,1]`, then `encoded = [1,2,3]`.

You are given the `encoded` array. You are also given an integer `first`, that is the first element of `arr`, i.e. `arr[0]`.

Return the original array `arr`. It can be proved that the answer exists and is unique.

**Example 1:**

```
Input: encoded = [1,2,3], first = 1
Output: [1,0,2,1]
Explanation: If arr = [1,0,2,1], then first = 1 and encoded = [1 XOR 0, 0 XOR 2, 2 XOR 1] = [1,2,3]
```

**Constraints:**

- `2 <= n <= 10^4`
- `encoded.length == n - 1`
- `0 <= encoded[i] <= 10^5`
- `0 <= first <= 10^5`


---
## 解決思路

因為題目已經給了original array的第一個元素，所以我們只要將此第一個元素與`encoded`中的第一個元素做XOR就可以還原原本在original array中的第二的元素。如此反覆還原後，即可得到原本的original array。 