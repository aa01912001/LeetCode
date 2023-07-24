題號: 1359. Count All Valid Pickup and Delivery Options
難度: Hard

## 問題描述
Given `n` orders, each order consist in pickup and delivery services. 

Count all valid pickup/delivery possible sequences such that delivery(i) is always after of pickup(i). 

Since the answer may be too large, return it modulo 10^9 + 7.

**Example 1:**
```
Input: n = 2
Output: 6
Explanation: All possible orders: 
(P1,P2,D1,D2), (P1,P2,D2,D1), (P1,D1,P2,D2), (P2,P1,D1,D2), (P2,P1,D2,D1) and (P2,D2,P1,D1).
This is an invalid order (P1,D2,P2,D1) because Pickup 2 is after of Delivery 2.
```
**Constraints:**

- `1 <= n <= 500`

## 解決思路
此題假設我們有`n`筆訂單，令p1,p2, ... ,pn為pickup事件，其排序有`n!`種可能。


對於任一排序(假設為p1,p2, ... ,pn)，我們考慮以下:

假設d1,d2, ... ,dn為對應的delivery事件。

我們希望插入dn，則只能放置pn之後，因此可能數為1

我們希望插入d_n-1，則只能在放置p_n-1後的位置放置，因此可能數為3

我們希望插入d_n-2，則只能在放置p_n-2後的位置放置，因此可能數為5

因此我們可以歸納出，對於`n`筆訂單，其解答公式為n!((1 * 3 * 5 * ... * (2n-1))

