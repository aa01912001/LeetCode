題號: 704. Binary Search

難度: Easy

## 問題描述
Given a **sorted** (in ascending order) integer array `nums` of `n` elements and a `target` value, write a function to search `target` in `nums`. If `target` exists, then return its index, otherwise return `-1`.

Example 1:

```
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
```

Note:

1. You may assume that all elements in `nums` are unique.
2. `n` will be in the range `[1, 10000]`.
3. The value of each element in `nums` will be in the range `[-9999, 9999]`.


---
## 解決思路
此題先將i設為0, j設為nums.size()-1，每次跌代都查看i、j中間之數是否等於target，若否，則根據中間值與target大小關係更新i or j值，最後若i > j則返回-1。
