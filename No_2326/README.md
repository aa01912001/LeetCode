題號: 2326. Spiral Matrix IV

難度: Medium

## 問題描述
You are given two integers `m` and `n`, which represent the dimensions of a matrix.

You are also given the `head` of a linked list of integers.

Generate an `m x n` matrix that contains the integers in the linked list presented in spiral order (clockwise), starting from the top-left of the matrix. If there are remaining empty spaces, fill them with `-1`.

Return the generated matrix.
![ex1new](https://hackmd.io/_uploads/rJkTe5vBxg.jpg)
**Example 1:**
```
Input: m = 3, n = 5, head = [3,0,2,6,8,1,7,9,4,2,5,5,0]
Output: [[3,0,2,6,8],[5,0,-1,-1,1],[5,2,4,9,7]]
Explanation: The diagram above shows how the values are printed in the matrix.
Note that the remaining spaces in the matrix are filled with -1.
```

**Constraints:**

- `1 <= m, n <= 105`
- `1 <= m * n <= 105`
- The number of nodes in the list is in the range `[1, m * n]`.
- `0 <= Node.val <= 1000`


**解決思路:**

這題就只是我們分別考慮往右、下、左、上走的時候需要走多少步，並且到盡頭後需重新換方向並計算該新方向可走的步數而已。

需要稍微思考的是計算可走步數的公式而已。