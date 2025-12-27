題號: 2483. Minimum Penalty for a Shop

難度: `Medium`

## 問題描述

You are given the customer visit log of a shop represented by a **0-indexed string** `customers` consisting only of characters `'N'` and `'Y'`:

- if the `i`-th character is `'Y'`, it means that customers come at the `i`-th hour  
- whereas `'N'` indicates that no customers come at the `i`-th hour.

If the shop closes at the `j`-th hour (`0 <= j <= n`), the **penalty** is calculated as follows:

- For every hour when the shop is **open** and no customers come, the penalty increases by `1`.
- For every hour when the shop is **closed** and customers come, the penalty increases by `1`.

Return **the earliest hour** at which the shop must be closed to incur a **minimum penalty**.

**Note:** If a shop closes at the `j`-th hour, it means the shop is closed at hour `j`.



**Example 1:**
```
Input: customers = "YYNY"
Output: 2
Explanation: 
- Closing the shop at the 0th hour incurs in 1+1+0+1 = 3 penalty.
- Closing the shop at the 1st hour incurs in 0+1+0+1 = 2 penalty.
- Closing the shop at the 2nd hour incurs in 0+0+0+1 = 1 penalty.
- Closing the shop at the 3rd hour incurs in 0+0+1+1 = 2 penalty.
- Closing the shop at the 4th hour incurs in 0+0+1+0 = 1 penalty.
Closing the shop at 2nd or 4th hour gives a minimum penalty. Since 2 is earlier, the optimal closing time is 2.
```
**Constraints:**

- `1 <= customers.length <= 105`
- `customers` consists only of characters `'Y'` and `'N'`.

**解決思路:**

此題我們需要得知`open 時間中 N 的數量 + closed 時間中 Y 的數量`。

因此我們事先計算所有`Y`的個數並存於`penalty`，代表了若在`hour=0`關店，所得到的懲罰。

之後我們開始遍歷`customers`，若`customers[i] == 'Y'`則代表若關店時間為`i+1`的話，時間`i`將變得不會得到懲罰了，因此我們將`penalty -= 1`，反之`customers[i] == 'N'`的話，則`penalty += 1`。

每回合我們都必須比較當前`penalty`是否小於我們記錄起來的`min_penalty`，若是，則將解答最佳營業時間更新為`i + 1`，`min_penalty = penalty`。