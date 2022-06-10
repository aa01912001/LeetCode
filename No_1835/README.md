題號: 1835. Find XOR Sum of All Pairs Bitwise AND
難度: Hard

## 問題描述

The **XOR sum** of a list is the bitwise `XOR` of all its elements. If the list only contains one element, then its **XOR sum** will be equal to this element.

- For example, the **XOR sum** of `[1,2,3,4]` is equal to `1 XOR 2 XOR 3 XOR 4 = 4`, and the **XOR sum** of `[3]` is equal to `3`.

You are given two **0-indexed** arrays `arr1` and `arr2` that consist only of non-negative integers.

Consider the list containing the result of `arr1[i] AND arr2[j]` (bitwise `AND`) for every `(i, j)` pair where `0 <= i < arr1.length` and `0 <= j < arr2.length`.

Return the **XOR sum** of the aforementioned list.

**Example 1:**
```
Input: arr1 = [1,2,3], arr2 = [6,5]
Output: 0
Explanation: The list = [1 AND 6, 1 AND 5, 2 AND 6, 2 AND 5, 3 AND 6, 3 AND 5] = [0,1,2,0,2,1].
The XOR sum = 0 XOR 1 XOR 2 XOR 0 XOR 2 XOR 1 = 0.
```
**Constraints:**

- 1 <= arr1.length, arr2.length <= 10^5
- 0 <= arr1[i], arr2[j] <= 10^9

---
## 解決思路

此題我們可以將各個bit分開來看，假設：
arr1 = [1,2,3], arr2 = [6,5]

0th bit個數為：
arr1 => 2
arr2 => 1
我們可以知道(1 AND 6) XOR (1 AND 5) XOR (2 AND 6) XOR (2 AND 5) XOR (3 AND 6) XOR (3 AND 5)其0th bit為0。

因此我們可以歸納出對於第ith bit，((其於arr1的個數)\*(其於arr2的個數)) % 2 == 1代表此bit在經過所有運算後會保留下來。

故我們在程式中只需要將各個bit分開計算後，最後若有保留，則將其權重加至解答中即可。
