題號: 1833. Maximum Ice Cream Bars
難度: Medium

## 問題描述

It is a sweltering summer day, and a boy wants to buy some ice cream bars.

At the store, there are n ice cream bars. You are given an array `costs` of length `n`, where `costs[i]` is the price of the `ith` ice cream bar in `coins`. The boy initially has coins coins to spend, and he wants to buy as many ice cream bars as possible. 

Return the **maximum** number of ice cream bars the boy can buy with coins coins.

**Note:** The boy can buy the ice cream bars in any order.

**Example 1:**
```
Input: costs = [1,3,2,4,1], coins = 7
Output: 4
Explanation: The boy can buy ice cream bars at indices 0,1,2,4 for a total price of 1 + 3 + 2 + 1 = 7.
```
**Constraints:**

- `costs.length == n`
- `1 <= n <= 10^5`
- `1 <= costs[i] <= 10^5`
- `1 <= coins <= 10^8`

---
## 解決思路

此題相當於0/1背包問題，因此我們首先對`costs`做sorting後，再依序購買較便宜的ice cream bar，直到`coins`不足即可。