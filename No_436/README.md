題號: 436. Find Right Interval
難度: Medium

## 問題描述

You are given an array of `intervals`, where `intervals[i] = [starti, endi]` and each `starti` is **unique**.

The **right interval** for an interval `i` is an interval `j` such that `startj >= endi` and `startj` is **minimized**. Note that `i` may equal `j`.

Return an array of **right interval** indices for each interval `i`. If no **right interval** exists for interval `i`, then put `-1` at index `i`.

**Example 1:**
```
Input: intervals = [[3,4],[2,3],[1,2]]
Output: [-1,0,1]
Explanation: There is no right interval for [3,4].
The right interval for [2,3] is [3,4] since start0 = 3 is the smallest start that is >= end1 = 3.
The right interval for [1,2] is [2,3] since start1 = 2 is the smallest start that is >= end2 = 2.
```

**Constraints:**

- `1 <= intervals.length <= 2 * 10^4`
- `intervals[i].length == 2`
- `-10^6 <= starti <= endi <= 10^6`
- The start point of each interval is **unique**.

---
## 解決思路

此題我們可以先對intervals做sorting，使其按照start由小至大排序，之後對於每一個`interval[i]`的`endi`，我們可以使用**binary search**的方式在sort過後的`intervals`中尋找某個最靠近`interval[i][1]`的`interval[j][0]`。