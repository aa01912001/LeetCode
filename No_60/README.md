題號: 60. Permutation Sequence
難度: hard

## 問題描述
The set `[1, 2, 3, ..., n]` contains a total of `n!` unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for `n = 3`:


`"123"`
`"132"`
`"213"`
`"231"`
`"312"`
`"321"`

Given `n` and `k`, return the `kth` permutation sequence.

**Example 1:**
```
Input: n = 3, k = 3
Output: "213"
```

**Constraints:**

- `1 <= n <= 9`
- `1 <= k <= n!`

---
## 解決思路
此題我們假設要決定最左邊的數字，我們需要找出一數盡可能小的數(假設為`lowerBound`)其乘上右邊剩下的位數個數之階層(假設為`factorial`)必不會超過`k`，因此我們就能知道當前位子的數應該為剩下的所有數字中第`lowerBound`大的數。

例如:
`n = 4, k = 9`
我們欲找出最左邊的數字為何，則此右邊三位的`factorial`為6。
假設最左數為`1`，則所有的階層可能為6 < `k`，因此最左數不可能為`1`。
假設最左數為`2`，則所有的階層可能為6\*2 >= `k`，因此最左數應為`2`。


同理我們欲找出左邊第二位的數，其右二位的`factorial`為2。
因為我們已經排除掉最左數為`1`的6的可能數量，因此當前`k = 9 - 6 = 3`。
假設左邊第二位的數為`1`，則所有的階層可能為6 < `k`，因此左邊第二位不可能為`1`。
假設左邊第二位的數為`3`(`2`已經被用掉，所以我們應該找次大的數)，則所有的階層可能為2\*2 >= `k`，因此最左數應為當前所剩數中第2大的數`3`。

而對於後續位數的找尋方式同理。