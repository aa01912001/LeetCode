題號: 1009. Complement of Base 10 Integer

難度: Easy

## 問題描述
Every non-negative integer `N` has a binary representation.  For example, `5` can be represented as `"101"` in binary, `11` as `"1011"` in binary, and so on.  Note that except for `N = 0`, there are no leading zeroes in any binary representation.

The complement of a binary representation is the number in binary you get when changing every `1` to a `0` and `0` to a `1`.  For example, the complement of `"101"` in binary is `"010"` in binary.

For a given number `N` in base-10, return the complement of it's binary representation as a base-10 integer.

Example 1:

```
Input: 5
Output: 2
Explanation: 5 is "101" in binary, with complement "010" in binary, which is 2 in base-10.
```

Note:

1. `0 <= N < 10^9`
2. This question is the same as 476



---
## 解決思路
此題利用檢查N的每個2進位之每個位數(由低到高)，我們可以觀察到兩種情況:

case 1: 該位等於 1
    直接略過(因為補數後會等於0)。
    
case 2: 該位等於 0
    將ret變數加上 2^該位的exponent。
    
最後即可得到N做補數後的十進位值(ret)。
