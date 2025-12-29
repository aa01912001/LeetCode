題號: 2768. Number of Black Blocks

難度: `Medium`

## 問題描述

You are given two integers `m` and `n` representing the dimensions of a **0-indexed** `m × n` grid.

You are also given a **0-indexed 2D integer matrix** `coordinates`, where  
`coordinates[i] = [x, y]` indicates that the cell with coordinates `[x, y]` is colored **black**.  
All cells in the grid that do not appear in `coordinates` are **white**.

A block is defined as a `2 × 2` submatrix of the grid.  
More formally, a block with cell `[x, y]` as its top-left corner where  
`0 ≤ x < m - 1` and `0 ≤ y < n - 1` contains the coordinates`[x, y]`,`[x + 1, y]`,`[x, y + 1]`,`[x + 1, y + 1]`.

Return a **0-indexed** integer array `arr` of size `5` such that  
`arr[i]` is the number of blocks that contain exactly `i` **black** cells.

**Example 1:**
![圖片](https://hackmd.io/_uploads/S1r4sgeNbx.png)
```
Input: m = 3, n = 3, coordinates = [[0,0],[1,1],[0,2]]
Output: [0,2,2,0,0]
Explanation: The grid looks like this:

There are 2 blocks with two black cells (the ones starting with cell coordinates [0,0] and [0,1]).
The other 2 blocks have starting cell coordinates of [1,0] and [1,1]. They both have 1 black cell.
Therefore, we return [0,2,2,0,0].
```
**Constraints:**

- `2 <= m <= 10^5`
- `2 <= n <= 10^5`
- `0 <= coordinates.length <= 10^4`
- `coordinates[i].length == 2`
- `0 <= coordinates[i][0] < m`
- `0 <= coordinates[i][1] < n`
- It is guaranteed that `coordinates` contains pairwise distinct coordinates.

**解決思路:**

我們可以逆向思考，若某個位置`(x, y)`為黑色的區塊，那麼它可能會影響的那些block的左上角位置，必定為將`(x, y)`作為右下角向左上方展開的2x2個grid。

因此我們只需要迭代`coordinates`，並且將每個`coordinate`所有的對應四格位置都加上1個count值，但若有某格的位置不滿足:`0 <= grid_i < m - 1 and 0 <= grid_j < n - 1`的話，代表那個位置不能表示為一個block，因此我們就忽略這個位置。

最後我們透過統計後的資訊就可以知道包含1, 2, 3, 4個黑色區塊的block數量。

而包含0個黑色的區塊數量就是將所有合法的block數量(`(m - 1) * (n - 1)`)減去上述包含1, 2, 3, 4個黑色區塊所有block數量即可得到。
