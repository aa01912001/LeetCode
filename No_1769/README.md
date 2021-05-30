題號: 1769. Minimum Number of Operations to Move All Balls to Each Box

難度: Medium

## 問題描述

You have `n` boxes. You are given a binary string `boxes` of length `n`, where `boxes[i]` is `'0'` if the `ith` box is **empty**, and `'1'` if it contains **one** ball.

In one operation, you can move **one** ball from a box to an adjacent box. Box `i` is adjacent to box `j` if `abs(i - j) == 1`. Note that after doing so, there may be more than one ball in some boxes.

Return an array `answer` of size `n`, where `answer[i]` is the **minimum** number of operations needed to move all the balls to the `ith` box.

Each `answer[i]` is calculated considering the **initial** state of the boxes.

Example 1:

```
Input: boxes = "110"
Output: [1,1,3]
Explanation: The answer for each box is as follows:
1) First box: you will have to move one ball from the second box to the first box in one operation.
2) Second box: you will have to move one ball from the first box to the second box in one operation.
3) Third box: you will have to move one ball from the first box to the third box in two operations, and move one ball from the second box to the third box in one operation.
```

Constraints:

- `n == boxes.length`
- `1 <= n <= 2000`
- `boxes[i]` is either `'0'` or `'1'`.


---
## 解決思路

此題我們可分為三階段步驟:
1. 計算位置`i`的左邊之'1'搬過來要多少moves，儲存在 `vector<int> rightAccu`中。
2. 計算位置`i`的右邊之'1'搬過來要多少moves，儲存在 `vector<int> leftAccu`中。
3. 加總前兩階段得到位置`i`之Minimum Number of Operations。

舉例:
在由左至右遍歷期間，我們可用`nums`變數紀錄之前遇到多少的'1'，而在計算`rightAccu[i]`時，則是將`rightAccu[i-1]`與`nums`相加即可(因為每跨一位置需要增加的數目為當前遇到之'1'數量)。