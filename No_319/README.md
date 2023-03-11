題號: 319. Bulb Switcher
難度: Medium

## 問題描述
There are `n` bulbs that are initially off. You first turn on all the bulbs, then you turn off every second bulb.

On the third round, you toggle every third bulb (turning on if it's off or turning off if it's on). For the `ith` round, you toggle every `i` bulb. For the `nth` round, you only toggle the last bulb.

Return the number of bulbs that are on after `n` rounds.

**Example 1:**
![](https://i.imgur.com/7V4UTfY.png)
```
Input: n = 3
Output: 1
Explanation: At first, the three bulbs are [off, off, off].
After the first round, the three bulbs are [on, on, on].
After the second round, the three bulbs are [on, off, on].
After the third round, the three bulbs are [on, off, off]. 
So you should return 1 because there is only one bulb is on.
```

**Constraints:**

- `0 <= n <= 10^9`

---
## 解決思路
我們知道第i個位置的燈泡只會被其因數位置的回合所觸發。

我們對24做因式分解，可以得到:
(1, 24) (2, 12) (3, 8) (4, 6)
可以發現每個pairs中的因數都是不同的數字，且總體因數個數為偶數，因此最後該位置的燈泡為off。

我們再對9做因式分解，可以得到:

(1, 9) (3, 3)
可以發現因數個數為奇數，因此該位置燈泡最後為on;而因數個數為奇數原因在於(3, 3)這個pair中的數為相同數字，因此我們可以知道若一個數為完全平方數的話，其不同因數個數必為奇數，否則為偶數。

藉由上述可知我們只需要找出1~n之間的所有完全平方數即為正確解答。
