題號: 1288. Remove Covered Intervals

難度: Medium

## 問題描述

Given an array `intervals` where `intervals[i] = [li, ri]` represent the interval `[li, ri)`, remove all intervals that are covered by another interval in the list.

The interval `[a, b)` is covered by the interval `[c, d)` if and only if `c <= a` and` b <= d`.

Return the number of remaining intervals.

**Example 1:**

```
Input: intervals = [[1,4],[3,6],[2,8]]
Output: 2
Explanation: Interval [3,6] is covered by [2,8], therefore it is removed.
```

**Constraints:**

- `1 <= intervals.length <= 1000`
- `intervals[i].length == 2`
- `0 <= li <= ri <= 10^5`
- All the given intervals are **unique**.



---
## 解決思路

此題我們先將`intervals`依照包含範圍由range小到range大的做排序，之後就能夠輕易地將被包含的數量算出。


