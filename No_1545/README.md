題號: 1545. Find Kth Bit in Nth Binary String

難度: Medium

## 問題描述

Given two positive integers `n` and `k`, the binary string  `Sn` is formed as follows:

- `S1 = "0"`
- `Si = Si-1 + "1" + reverse(invert(Si-1))` for `i > 1`

Where `+` denotes the concatenation operation, `reverse(x)` returns the reversed string x, and `invert(x)` inverts all the bits in x (0 changes to 1 and 1 changes to 0).

For example, the first 4 strings in the above sequence are:

- `S1 = "0"`
- `S2 = "011"`
- `S3 = "0111001"`
- `S4 = "011100110110001"`

Return the `kth` bit in `Sn`. It is guaranteed that `k` is valid for the given `n`.

**Example 1:**

```
Input: n = 3, k = 1
Output: "0"
Explanation: S3 is "0111001". The first bit is "0".
```

**Constraints:**

- `1 <= n <= 20`
- `1 <= k <= 2^n - 1`



---
## 解決思路

此題只需要利用遞迴策略來從S0建構出Sn即可，而對於reverse()與invert()則另外實作出即可。


