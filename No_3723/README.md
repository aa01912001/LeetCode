題號: 3723. Maximize Sum of Squares of Digits

難度: `Medium`

## 問題描述

You are given two **positive** integers `num` and `sum`.

A positive integer `n` is **good** if it satisfies both of the following:

* The number of digits in `n` is **exactly** `num`.
* The sum of digits in `n` is **exactly** `sum`.

The **score** of a **good** integer `n` is the sum of the squares of digits in `n`.

Return a **string** denoting the **good** integer `n` that achieves the **maximum score**. If there are multiple possible integers, return the **maximum** one. If no such integer exists, return an empty string.


**Example 1:**
```
Input: num = 2, sum = 3

Output: "30"

Explanation:

There are 3 good integers: 12, 21, and 30.

    The score of 12 is 12 + 22 = 5.
    The score of 21 is 22 + 12 = 5.
    The score of 30 is 32 + 02 = 9.

The maximum score is 9, which is achieved by the good integer 30. Therefore, the answer is "30".
```
**Constraints:**

- `1 <= num <= 2 * 10^5`
- `1 <= sum <= 2 * 10^6`

**解決思路:**

此題我們採用Greedy的方式嘗試透過由左至右（從最高位到最低位）依序決定每個位數的數字即可。

但一開始我們需要確認給定的 sum 是否合法。如果總和超過了 num 位數最大值（9 * num），直接回傳空字串。