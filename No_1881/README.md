題號: 1881. Maximum Value after Insertion
難度: Medium

## 問題描述

You are given a very large integer `n`, represented as a string, and an integer digit `x`. The digits in `n` and the digit `x` are in the **inclusive** range `[1, 9]`, and n may represent a **negative** number.

You want to **maximize** `n`**'s numerical value** by inserting `x` anywhere in the decimal representation of `n`. You **cannot** insert `x` to the left of the negative sign.


- For example, if` n = 73` and `x = 6`, it would be best to insert it between `7` and `3`, making `n = 763`.
- If `n = -55` and `x = 2`, it would be best to insert it before the first `5`, making `n = -255`.

Return a string representing the **maximum** value of `n` after the insertion.

**Example 1:**

```
Input: n = "-13", x = 2
Output: "-123"
Explanation: You can make n one of {-213, -123, -132}, and the largest of those three is -123.
```

**Constraints:**

- `1 <= n.length <= 10^5`
- `1 <= x <= 9`
- The digits in `n` are in the range `[1, 9]`.
- `n` is a valid representation of an integer.
- In the case of a negative `n`, it will begin with `'-'`.

---
## 解決思路

此題首先先判斷`n`為正數或負數，若為正數，則若`x`越大則應該放在越左邊，因此我們採用Greedy的方式每次從左到右判斷各digit與`x`的大小關係，若x大於當前digit，則插入至此digit之前即可；若`x`為負數，則越大的則因該放置越右邊，因此可同理操作。