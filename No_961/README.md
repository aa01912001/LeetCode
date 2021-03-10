題號: N-Repeated Element in Size 2N Array

難度: Easy

## 問題描述
In a array `A` of size `2N`, there are `N+1` unique elements, and exactly one of these elements is repeated `N` times.

Return the element repeated `N` times.

Example 1:

```
Input: [1,2,3,3]
Output: 3
```

Note:


- `4 <= A.length <= 10000`
- `0 <= A[i] < 10000`
- `A.length` is even


---
## 解決思路

此題只要利用`unordered_set`遍歷`A`來儲存出現過的unique number即可。過程中一旦發現有某個數字已經被儲存在set中，即返回之。