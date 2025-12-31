題號: 1970. Last Day Where You Can Still Cross

難度: `Hard`

## 問題描述

There is a **1-based binary matrix** where `0` represents **land** and `1` represents **water**.  
You are given integers `row` and `col` representing the number of rows and columns in the matrix, respectively.

Initially on **day 0**, the **entire matrix is land**. However, each day a new cell becomes flooded with **water**.  
You are given a **1-based** 2D array `cells`, where `cells[i] = [ri, ci]` represents that on the *i-th day*,  
the cell on the `ri`-th row and `ci`-th column (**1-based coordinates**) will be covered with water  
(i.e., changed to `1`).

You want to find the **last day** that it is possible to walk from the **top** to the **bottom** by only walking on **land cells**. You can start from **any** cell in the top row and end at **any** cell in the bottom row. You can only travel in the **four** cardinal directions (left, right, up, and down).

Return the **last day** where it is possible to walk from the **top** to the **bottom** by only walking on land cells.


**Example 1:**
![圖片](https://hackmd.io/_uploads/SJl7L4GVZe.png)
```
Input: row = 3, col = 3, cells = [[1,2],[2,1],[3,3],[2,2],[1,1],[1,3],[2,3],[3,2],[3,1]]
Output: 3
Explanation: The above image depicts how the matrix changes each day starting from day 0.
The last day where it is possible to cross from top to bottom is on day 3.
```
**Constraints:**

- `2 <= row, col <= 2 * 10^4`
- `4 <= row * col <= 2 * 10^4`
- `cells.length == row * col`
- `1 <= ri <= row`
- `1 <= ci <= col`
- All the values of `cells` are **unique**.

**解決思路:**

我們可以觀察如果想防止從頂部走到底部（只走陸地），唯一的辦法就是防止水域形成一條從左側連到右側的「水帶」。因此我們可以使用Union-Find的方式來解決此題。另外在判斷水域連通時，我們必須包含斜對角（8個方向），因為人雖然不能斜著走陸地。

另外我們可以額外建立兩個虛擬節點:
- LEFT_BOUND：所有位於第一列 (c=1) 的水滴都會與它相連。
- RIGHT_BOUND：所有位於最後一列 (c=col) 的水滴都會與它相連。

接下來我們可以依序迭代`cells`來演進水帶:

1. 第 i 天，某個座標 (r,c) 變成水。
2. 檢查這個(r,c)周圍 8 個方向，如果有任何鄰居已經也是水了，就用 union 把它們合併到同一個集合中。
3. 邊界觸碰
    - 如果(r,c)在最左邊，union(current, LEFT_BOUND)。
    - 如果(r,c)在最右邊，union(current, RIGHT_BOUND)。
4. 確認`find(LEFT_BOUND) == find(RIGHT_BOUND)`，若成立代表已經有一條水帶可滿足從左一路連到右邊了，因此我們就可以回傳當下的時間點作為答案。