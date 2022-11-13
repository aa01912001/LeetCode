題號: 1552. Magnetic Force Between Two Balls
難度: Medium

## 問題描述

In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they are put in his new invented basket. Rick has `n` empty baskets, the `ith` basket is at `position[i]`, Morty has `m` balls and needs to distribute the balls into the baskets such that the **minimum magnetic force** between any two balls is **maximum**.

Rick stated that magnetic force between two different balls at positions `x` and `y` is `|x - y|`.

Given the integer array `position` and the integer `m`. Return the required force.

**Example 1:**
![image alt](![](https://i.imgur.com/Xl11Qci.png)
```
Input: position = [1,2,3,4,7], m = 3
Output: 3
Explanation: Distributing the 3 balls into baskets 1, 4 and 7 will make the magnetic force between ball pairs [3, 3, 6]. The minimum magnetic force is 3. We cannot achieve a larger minimum magnetic force than 3.
```

**Constraints:**

- `n == position.length`
- `2 <= n <= 10^5`
- `1 <= position[i] <= 10^9`
- All integers in `position` are **distinct**.
- `2 <= m <= position.length`

---
## 解決思路

此題我們可以利用binary search的方式來逼近解答，在每一次的猜測的我們必須判斷此次的猜測值是否可在m顆球的情況下滿足。

假設猜測值為`mid`那麼我們可以從`position[0]`開始嘗試把球放入，一旦兩顆球的位置大於等於`mid`，我們就將count數加1，最後判斷count值是否大於等於m即可。