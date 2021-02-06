題號: 1267. Count Servers that Communicate

難度: Medium

## 問題描述
You are given a map of a server center, represented as a `m * n` integer matrix `grid`, where 1 means that on that cell there is a server and 0 means that it is no server. Two servers are said to communicate if they are on the same row or on the same column.

Return the number of servers that communicate with any other server.

Example 1:
![](https://assets.leetcode.com/uploads/2019/11/14/untitled-diagram-1-3.jpg)

```
Input: grid = [[1,1,0,0],[0,0,1,0],[0,0,1,0],[0,0,0,1]]
Output: 4
Explanation: The two servers in the first row can communicate with each other. The two servers in the third column can communicate with each other. The server at right bottom corner can't communicate with any other server.
```
Constraints:


- `m == grid.length`
- `n == grid[i].length`
- `1 <= m <= 250`
- `1 <= n <= 250`
- `grid[i][j] == 0 or 1`

---
## 解決思路
此題首先計算每個row跟column上擁有的server數量，將之加總後減去無法跟別人溝通的server(即該row與該column上只有自己的server)數量乘以2(因為row跟column加總會重複計算)，最後得到的值除以2(因為row跟column加總會重複計算)即為解答。