題號: 526. Beautiful Arrangement

難度: Medium

## 問題描述

Suppose you have `n` integers labeled `1` through `n`. A permutation of those `n` integers `perm` (**1-indexed**) is considered a **beautiful arrangement** if for every `i` (`1 <= i <= n`), **either** of the following is true:

- `perm[i]` is divisible by `i`.
- `i` is divisible by `perm[i]`.

Given an integer n, return the **number** of the **beautiful arrangements** that you can construct.

Example 1:

```
Input: n = 2
Output: 2
Explanation: 
The first beautiful arrangement is [1,2]:
    - perm[1] = 1 is divisible by i = 1
    - perm[2] = 2 is divisible by i = 2
The second beautiful arrangement is [2,1]:
    - perm[1] = 2 is divisible by i = 1
    - i = 2 is divisible by perm[2] = 1
```

Constraints:

- `1 <= n <= 15`



---
## 解決思路

此題可以利用**backtracking**來遍歷1~n的**permutation**，過程中只要發現規則不成立的擺放，就放棄搜尋這個候選**permutation**，轉而尋找下一個可能的**permutation**。最後只要發現有一組每個位置都滿足規則的**permutation**，就將回傳值加1。
