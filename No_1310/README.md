題號: XOR Queries of a Subarray

難度: Medium

## 問題描述
Given the array `arr` of positive integers and the array `queries` where `queries[i] = [Li, Ri]`, for each query `i` compute the **XOR** of elements from `Li` to `Ri` (that is, `arr[Li] xor arr[Li+1] xor ... xor arr[Ri]` ). Return an array containing the result for the given `queries`.

Example 1:
```
Input: arr = [1,3,4,8], queries = [[0,1],[1,2],[0,3],[3,3]]
Output: [2,7,14,8] 
Explanation: 
The binary representation of the elements in the array are:
1 = 0001 
3 = 0011 
4 = 0100 
8 = 1000 
The XOR values for queries are:
[0,1] = 1 xor 3 = 2 
[1,2] = 3 xor 4 = 7 
[0,3] = 1 xor 3 xor 4 xor 8 = 14 
[3,3] = 8
```

---
## 解決思路
我們首先去計算**arr[0] Xor arr[1] Xor arr[2] Xor ... Xor arr[i], i from 0 to arr.size() - 1**，並保存在iXor之vector中。我們即可利用此iXor vector去計算queries，範例如下:

queries中的某項 [i, j] 之對應解為: iXor[j] **Xor** iXor[i-1]。

此想法是透過四個Xor運算之重要原理:

**1. i Xor i = 0**
**2. i Xor 0 = i**
**3. i Xor j = j Xor i**
**4. (i Xor j) Xor k = i Xor (j Xor k) **