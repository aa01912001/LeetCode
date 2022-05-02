題號: 1605. Find Valid Matrix Given Row and Column Sums
難度: Medium

## 問題描述

You are given two arrays `rowSum` and `colSum` of non-negative integers where `rowSum[i]` is the sum of the elements in the `ith` row and `colSum[j]` is the sum of the elements of the `jth` column of a 2D matrix. In other words, you do not know the elements of the matrix, but you do know the sums of each row and column.

Find any matrix of **non-negative** integers of size `rowSum.length x colSum.length` that satisfies the `rowSum` and `colSum` requirements.

Return a 2D array representing **any** matrix that fulfills the requirements. It's guaranteed that **at least one** matrix that fulfills the requirements exists.

**Example 1:**
```
Input: rowSum = [3,8], colSum = [4,7]
Output: [[3,0],
         [1,7]]
Explanation: 
0th row: 3 + 0 = 3 == rowSum[0]
1st row: 1 + 7 = 8 == rowSum[1]
0th column: 3 + 1 = 4 == colSum[0]
1st column: 0 + 7 = 7 == colSum[1]
The row and column sums match, and all matrix elements are non-negative.
Another possible matrix is: [[1,2],
                             [3,5]]
```

**Constraints:**

- `1 <= rowSum.length, colSum.length <= 500`
- `0 <= rowSum[i], colSum[i] <= 10^8`
- `sum(rows) == sum(columns)`

---
## 解決思路

此題在建構矩陣(命名為`ret`)時，對於`ret[i][j]`來說，我們賦予其`min(rowSum[i], colSum[j])`後，在從`rowSum[i]`與`colSum[j]`減去其值，如此建構到最後即可得到最終的解答矩陣。

證明：由於每次都取`rowSum[i]`與`colSum[j]`中的最小值，因此會使其中一個值變為0，如此取到最後會使得`rowSum`與`colSum`皆為0，而過程中取最小值同時也保證加入此元素後不會造成某row或某column超出其規範之總和。

