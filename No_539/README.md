題號: 539. Minimum Time Difference
難度: Medium

## 問題描述
Given a list of 24-hour clock time points in **"HH:MM"** format, return the minimum **minutes** difference between any two time-points in the list. 

**Example 1:**
```
Input: timePoints = ["00:00","23:59","00:00"]
Output: 0
```
**Constraints:**

- `2 <= timePoints.length <= 2 * 10^4`
- `timePoints[i]` is in the format **"HH:MM"**.

## 解決思路
此題我們首先對timePoints做遞增排序後，再依序計算出兩個相鄰的元素時間差即可。

另外，在計算時，我們記得要多考量頭尾元素的時間差是否在跨越00:00分時，會有最小的差距。