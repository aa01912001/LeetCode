題號: 1442. Count Triplets That Can Form Two Arrays of Equal XOR

難度: Medium

## 問題描述

Given an array of integers `arr`.

We want to select three indices `i`, `j` and `k` where `(0 <= i < j <= k < arr.length)`.

Let's define `a` and `b` as follows:

- `a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]`
- `b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]`
Note that **^** denotes the **bitwise-xor** operation.

Return the number of triplets (`i`, `j` and `k`) Where `a == b`.

**Example 1:**
```
Input: arr = [2,3,1,6,7]
Output: 4
Explanation: The triplets are (0,1,2), (0,2,2), (2,3,4) and (2,4,4)
```

**Constraints:**

- `1 <= arr.length <= 300`
- `1 <= arr[i] <= 10^8`


---
## 解決思路

此題相當於去尋找長度大於等於2的子陣列且其`XOR == 0`，一但找到，就將解答加上此子陣列的長度-1。

**證明如下：**

對於一個XOR為0的子陣列來說，必定可從中找到一個分割(兩子陣列各自索引為`i, i+1,..,j`與`k`)且各自的XOR相同(假設為`X`)，我們可將兩子陣列中間向左移一位得到兩個新的子陣列，其索引如下：

左子陣列：`i, i+1,...,j-1`，其XOR為`X`^`arr[j]`
右子陣列：`j, k`，其XOR為`X`^`arr[j]`

因此可得到新的triplet，使得`a == b`

以此類推，對於一個XOR為0的子陣列來說，我們可以得到其長度-1個triplet，使得`a == b`


