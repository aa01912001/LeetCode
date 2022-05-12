題號: 498. Diagonal Traverse
難度: Medium

## 問題描述

Given an `m x n` matrix `mat`, return an array of all the elements of the array in a diagonal order.

**Example 1:**
![image alt](https://assets.leetcode.com/uploads/2021/04/10/diag1-grid.jpg)
```
Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,4,7,5,3,6,8,9]
```
**Constraints:**

- `m == mat.length`
- `n == mat[i].length`
- `1 <= m, n <= 10^4`
- `1 <= m * n <= 10^4`
- `-10^5 <= mat[i][j] <= 10^5`

---
## 解決思路

首先，令`m = mat.size(), n = mat[0].size()`，我們可以很明顯地看出所有對角線的個數(`c`)為`m+n-1`，而針對第`i`條(從左上到右下)對角線中的元素，其座標總和必為`i`，因此我們可以歸納出：

第`i`條對角線的第一個元素為：

- `mat[min(m-1, i)][i-min(m-1, i)], if i%2 == 0`
- `mat[i-min(n-1, i)][min(n-1, i)], if i%2 == 1`

而每次找到第一個元素後就可以輕易地找出下一個對角線中的元素，歸納如下：

- `next = mat[pre--][pre++], if i%2 == 0`
- `next = mat[pre++][pre--], if i%2 == 1`

若超出邊界，則切換進行至下一個對角線(i+1)

如此我們就能夠找出一個矩陣的**Diagonal Traverse**。