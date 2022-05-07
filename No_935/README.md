題號: 935. Knight Dialer
難度: Medium

## 問題描述

The chess knight has a **unique movement**, it may move two squares vertically and one square horizontally, or two squares horizontally and one square vertically (with both forming the shape of an **L**). The possible movements of chess knight are shown in this diagaram:

A chess knight can move as indicated in the chess diagram below:
![image alt](https://assets.leetcode.com/uploads/2020/08/18/chess.jpg)
We have a chess knight and a phone pad as shown below, the knight **can only stand on a numeric cell** (i.e. blue cell).
![image alt](https://assets.leetcode.com/uploads/2020/08/18/phone.jpg)
Given an integer `n`, return how many distinct phone numbers of length `n` we can dial.

You are allowed to place the knight **on any numeric cell** initially and then you should perform `n - 1` jumps to dial a number of length `n`. All jumps should be **valid** knight jumps.

As the answer may be very large, **return the answer modulo** `10^9 + 7`.

**Example 1:**

```
Input: n = 2
Output: 20
Explanation: All the valid number we can dial are [04, 06, 16, 18, 27, 29, 34, 38, 40, 43, 49, 60, 61, 67, 72, 76, 81, 83, 92, 94]
```
**Constraints:**

- `1 <= n <= 5000`.

---
## 解決思路

此題我們DP的方式來解決，我們令`dp[i][j]`為長度`i+1`的號碼，且最後一個號碼為`j`之可能個數；我們可以觀察到數字0的前一個可能位置只有4、6，其他數字也可輕易觀察出來，因此我們在程式中事先建立一個位置表如下，表示每個數字前一個可能的位置。

```cpp=
vector<vector<int>> possiblePre = {
            {4, 6},
            {6, 8},
            {7, 9},
            {4, 8},
            {0, 3, 9},
            {},
            {0, 1, 7},
            {2, 6},
            {1, 3},
            {2, 4}
        };
```

對於長度為`i+1`且最後一個數字為0的可能號碼個數即為長度為`i`且最後一個數字為4與6之可能個數加總，因此dp的狀態轉移式如下：

```cpp=
dp[i][j] = dp[i][j] + dp[i-1][possiblePre[j][k]];
```

其中：
`i`代表當前號碼長度為`i+1`(因為**0-index**)
`J`代表當前號碼的最後一個數字為`j`;
`possiblePre[j][k]`代表`j`的前一個可能數字


在計算完所有dp後，我們只要將`sum(dp[n-1][0], dp[n-1][1], ... , dp[n-1][9])`返回即為所有長度為`n`之號碼個數。


