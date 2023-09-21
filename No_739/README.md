題號: 739. Daily Temperatures
難度: Medium

## 問題描述
Given an array of integers `temperatures` represents the daily temperatures, return an array `answer` such that `answer[i]` is the number of days you have to wait after the `ith` day to get a warmer temperature. If there is no future day for which this is possible, keep `answer[i] == 0` instead.

**Example 1:**
```
Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
```

**Constraints:**

- `1 <= temperatures.length <= 10^5`
- `30 <= temperatures[i] <= 100`

## 解決思路
此題我們利用monotonic stack的方式由`temperatures`後方開始儲存嚴格遞減的數列及其索引位置即可。

對於當前的`temperatures[i]`若stack top之氣溫大於他，我們就根據stack top之索引位置將答案放至解答中，否則我們不斷pop stack，直到stack top之氣溫大於`temperatures[i]`，並在最後將`temperatures[i]`與當前索引`i`放入stack中。

