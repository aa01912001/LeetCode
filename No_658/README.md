題號: 658. Find K Closest Elements

難度: Medium

## 問題描述

Given a **sorted** integer array `arr`, two integers `k` and `x`, return the `k` closest integers to `x` in the array. The result should also be sorted in ascending order.

An integer `a` is closer to `x` than an integer `b` if:
- `|a - x| < |b - x|`, or
- `|a - x| == |b - x|` and `a < b`

**Example 1:**

```
Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]
```


**Constraints:**

- `1 <= k <= arr.length`.
- `1 <= arr.length <= 10^4`
- `arr` is sorted in **ascending** order.
- `-10^4 <= arr[i], x <= 10^4`

---
## 解決思路

此題只需要利用two pointers的方式從`arr`頭和尾，分別向內尋找最靠近`x`的`k`範圍即可
當`arr[left]`與`x`的距離大於`arr[right]`與`x`的距離，我們就把`left`的索引值加一，否則就把`right`索引值加一。進行此操作到`left`與`right`的距離為`k-1`即可找出正確的範圍。



