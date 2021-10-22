題號: 397. Integer Replacement

難度: Medium

## 問題描述

Given a positive integer `n`, you can apply one of the following operations:

1. If `n` is even, replace n with `n / 2`.
2. If `n` is odd, replace `n` with either `n + 1` or `n - 1`.
Return the minimum number of operations needed for `n` to become `1`.

**Example 1:**

```
Input: n = 8
Output: 3
Explanation: 8 -> 4 -> 2 -> 1
```

**Constraints:**

- `1 <= n <= 2^31 - 1`


---
## 解決思路

此題我們需要先判斷`n`最右邊的bit是否為1(if n % 2 == 1)，若是的話則進一步判斷`n`最右邊兩個bits是否皆為1(if n % 3 == 1)，若也成立我們可以將n的值+1，因為將連續的1 bits加1後可以將之變為連續的0，進而節省後續成本。然而我們需要另外判斷當前n的值是否為大於3，因為當n等於3時，我應該直接除以二使之等於1，若加1的話反而會增加成本。






