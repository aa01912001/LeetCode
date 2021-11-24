題號: 838. Push Dominoes

難度: Medium

## 問題描述

There are `n` dominoes in a line, and we place each domino vertically upright. In the beginning, we simultaneously push some of the dominoes either to the left or to the right.

After each second, each domino that is falling to the left pushes the adjacent domino on the left. Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.

When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.

For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.

You are given a string `dominoes` representing the initial state where:

- `dominoes[i] = 'L'`, if the `ith` domino has been pushed to the left,
- `dominoes[i] = 'R'`, if the `ith` domino has been pushed to the right, and
- `dominoes[i] = '.'`, if the `ith` domino has not been pushed.

Return a string representing the final state.

**Example 1:**

![image alt](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/05/18/domino.png)

```
Input: dominoes = ".L.R...LR..L.."
Output: "LL.RR.LLRRLL.."
```

**Constraints:**

- `n == dominoes.length`
- `1 <= n <= 10^5`
- `dominoes[i]` is either `'L'`, `'R'`, or `'.'`.

---
## 解決思路

此題我們首先針對那些介於`'R'-'L'`pattern的字元去作處理，過程中我們用`int l`來記錄前一個`R`出現的位置，當我們搜尋到`L`後，就去轉換`R`~`L`之間的字元(左半邊變為`R`，右半邊變為`L`)。

之後接著處理那些一路往右倒或一路往左倒的位置即可。











