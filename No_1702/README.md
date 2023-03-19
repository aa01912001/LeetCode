題號: 1702. Maximum Binary String After Change
難度: Medium

## 問題描述
You are given a binary string `binary` consisting of only `0`'s or `1`'s. You can apply each of the following operations any number of times:

- Operation 1: If the number contains the substring `"00"`, you can replace it with `"10"`.
    - For example, `"00010" -> "10010"`

- Operation 2: If the number contains the substring `"10"`, you can replace it with `"01"`.
    - For example, `"00010" -> "00001"`

Return the **maximum binary string** you can obtain after any number of operations. Binary string `x` is greater than binary string `y` if `x`'s decimal representation is greater than `y`'s decimal representation.

**Example 1:**
```
Input: binary = "000110"
Output: "111011"
Explanation: A valid transformation sequence can be:
"000110" -> "000101" 
"000101" -> "100101" 
"100101" -> "110101" 
"110101" -> "110011" 
"110011" -> "111011"
```

**Constraints:**

- `1 <= binary.length <= 10^5`
- `binary` consist of `'0'` and `'1'`.

---
## 解決思路
此題我們透過觀察可以對於任何binery string我們一定可以將其變為只有一個`0`的形式。

對於從頭開始連續的`1`來說，我們不需要去更動，而對於剩下的`1`來說，我們可以透過操作將他們全部移至最右邊，使得我們的binary string形成`1110...01111`的形式。因此中間的`0`透過不斷的操作1，可以只留下最右邊的`0`，變為`1111...101111`。