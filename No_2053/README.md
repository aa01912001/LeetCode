題號: 2053. Kth Distinct String in an Array

難度: Easy

## 問題描述

A **distinct string** is a string that is present only **once** in an array.

Given an array of strings `arr`, and an integer `k`, return the `kth` **distinct string** present in `arr`. If there are **fewer** than `k` distinct strings, return an **empty string** `""`.

Note that the strings are considered in the **order in which they appear** in the array.

**Example 1:**
```
Input: arr = ["d","b","c","b","c","a"], k = 2
Output: "a"
Explanation:
The only distinct strings in arr are "d" and "a".
"d" appears 1st, so it is the 1st distinct string.
"a" appears 2nd, so it is the 2nd distinct string.
Since k == 2, "a" is returned. 
```


**Constraints:**

- `1 <= k <= arr.length <= 1000`
- `1 <= arr[i].length <= 5`
- `arr[i]` consists of lowercase English letters.

---
## 解決思路

此題首先利用`unordered_map<string, int> count`去紀錄`arr`中每個字串出現的次數，之後再重頭尋找**kth distinct string**即可。