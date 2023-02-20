題號: 2139. Minimum Moves to Reach Target Score
難度: Medium

## 問題描述
You are playing a game with integers. You start with the integer `1` and you want to reach the integer `target`.

In one move, you can either:

- **Increment** the current integer by one (i.e., `x = x + 1`).
- **Double** the current integer (i.e., `x = 2 * x`).

You can use the **increment** operation **any** number of times, however, you can only use the **double** operation **at most** `maxDoubles` times.

Given the two integers `target` and `maxDoubles`, return the minimum number of moves needed to reach `target` starting with `1`.

**Example 1:**
```
Input: target = 19, maxDoubles = 2
Output: 7
Explanation: Initially, x = 1
Increment 3 times so x = 4
Double once so x = 8
Increment once so x = 9
Double again so x = 18
Increment once so x = 19
```

**Constraints:**

- `1 <= target <= 10^9`
- `0 <= maxDoubles <= 100`

---
## 解決思路
由於任何整數乘以2皆為偶數，因此我們可以利用greedy的方式不斷地將`target`除以2，直至變為1。過程中若數字變為奇數，我們需要將解答值再另外加1(因為奇數一定是從距離他最近的偶數再加1而得)。最後若已經將`maxDoubles`用完，且`target`大於1，我們則另外加上剩餘數字減1，以補上不足的次數。