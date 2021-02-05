題號: 718. Maximum Length of Repeated Subarray

難度: Medium

## 問題描述
Given two integer arrays `A` and `B`, return the maximum length of an subarray that appears in both arrays.

Example 1:

```
Input:
A: [1,2,3,2,1]
B: [3,2,1,4,7]
Output: 3
Explanation: 
The repeated subarray with maximum length is [3, 2, 1].
```

Note:

1. 1 <= len(A), len(B) <= 1000
2. 0 <= A[i], B[i] < 100

---
## 解決思路
此題相當於**Longest Common Sequence**的變形題，同樣可以利用DP的方式來解，程式中dp[i][j]相當於包含A[i-1]與B[j-1]字元的最長重複子陣列，所以我們可以知道若A[i-1]不等於B[j-1]，那麼dp[i][j]勢必為0，若相同則`dp[i][j] = dp[i-1][j-1] + 1`。最後只要找出dp中最大的數即為解答。