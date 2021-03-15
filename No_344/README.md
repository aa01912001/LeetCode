題號: 344. Reverse String

難度: Easy

## 問題描述
Write a function that reverses a string. The input string is given as an array of characters `char[]`.

Do not allocate extra space for another array, you must do this by **modifying the input array** `in-place` with O(1) extra memory.

You may assume all the characters consist of `printable ascii characters`.

Example 1:

```
Input: ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
```

---
## 解決思路

此題只要利用兩個索引指標從vector前後開始向內交換字元即可。
