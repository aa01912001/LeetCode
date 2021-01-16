題號: 1344. Angle Between Hands of a Clock

難度: Medium

## 問題描述
Given two numbers, `hour` and `minutes`. Return the smaller angle (in degrees) formed between the `hour` and the `minute` hand.

Example 1:
![](https://assets.leetcode.com/uploads/2019/12/26/sample_1_1673.png)

```
Input: hour = 12, minutes = 30
Output: 165
```

Constraints:

- `1 <= hour <= 12`
- `0 <= minutes <= 59`
- Answers within `10^-5` of the actual value will be accepted as correct.
---
## 解決思路
首先將hour的刻度轉換成minutes的刻度，之後再利用hour與minutes兩刻度之間的差依比例轉換成度數(儲存在ret變數中)。最後選擇ret與(360-ret)較小的那個返回。

Note: 每個minutes的刻度差為6度，而每一hour的刻度差為30度。