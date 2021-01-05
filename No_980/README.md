題號: 980. Unique Paths III

難度: Hard

## 問題描述
On a 2-dimensional `grid`, there are 4 types of squares:

 - 1 represents the starting square.  There is exactly one starting square.
 - 2 represents the ending square.  There is exactly one ending square.
 - 0 represents empty squares we can walk over.
 - -1 represents obstacles that we cannot walk over.
Return the number of 4-directional walks from the starting square to the ending square, that **walk over every non-obstacle square exactly once**.


Example 1:

```
Input: [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
Output: 2
Explanation: We have the following two paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
```

Note:

1. `1 <= grid.length * grid[0].length <= 20`




---
## 解決思路
此題利用DFS窮舉所有可能的走法，直到走到2後再判斷是否已經走過所有的0(程式中利用事先計算好的0個數並存在zeros變數中來判斷，每次走過0就將zeros - 1)。在程式中，我們利用grid[y][x] = -2來紀錄已經走過的point以免再次拜訪。
