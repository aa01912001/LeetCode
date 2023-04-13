題號: 1010. Pairs of Songs With Total Durations Divisible by 60
難度: Medium

## 問題描述
You are given a list of songs where the `ith` song has a duration of `time[i]` seconds.

Return the number of pairs of songs for which their total duration in seconds is divisible by `60`. Formally, we want the number of indices `i`, `j` such that `i < j` with `(time[i] + time[j]) % 60 == 0`.

**Example 1:**
```
Input: time = [30,20,150,100,40]
Output: 3
Explanation: Three pairs have a total duration divisible by 60:
(time[0] = 30, time[2] = 150): total duration 180
(time[1] = 20, time[3] = 100): total duration 120
(time[1] = 20, time[4] = 40): total duration 60
```

**Constraints:**

- `1 <= time.length <= 6 * 10^4`
- `1 <= time[i] <= 500`

## 解決思路
此題我們只需要將每個`time[i] % 60`的個數記錄下來，之後對於後續元素來說，只要將其互補的出現次數加入至解答中即可。