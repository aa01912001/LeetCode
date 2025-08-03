題號: 2106. Maximum Fruits Harvested After at Most K Steps

難度: Hard

## 問題描述
Fruits are available at some positions on an infinite x-axis. You are given a 2D integer array `fruits` where `fruits[i] = [position_i, amount_i]` depicts `amount_i` fruits at the position `position_i`. `fruits` is already **sorted** by `position_i` in **ascending order**, and each `position_i` is **unique**.

You are also given an integer `startPos` and an integer `k`. Initially, you are at the position `startPos`. From any position, you can either walk to the **left or right**. It takes **one step** to move **one unit** on the x-axis, and you can walk **at most** `k` steps in total. For every position you reach, you harvest all the fruits at that position, and the fruits will disappear from that position.

Return the **maximum total number** of fruits you can harvest.

**Example 1:**
![2](https://hackmd.io/_uploads/r1MFjtnwex.png)
```
Input: fruits = [[0,9],[4,1],[5,7],[6,2],[7,4],[10,9]], startPos = 5, k = 4
Output: 14
Explanation: 
You can move at most k = 4 steps, so you cannot reach position 0 nor 10.
The optimal way is to:
- Harvest the 7 fruits at the starting position 5
- Move left to position 4 and harvest 1 fruit
- Move right to position 6 and harvest 2 fruits
- Move right to position 7 and harvest 4 fruits
You moved 1 + 3 = 4 steps and harvested 7 + 1 + 2 + 4 = 14 fruits in total.
```

**Constraints:**

- `1 <= fruits.length <= 10^5`
- `fruits[i].length == 2`
- `0 <= startPos, position_i <= 2 * 10^5`
- `position_i-1 < position_i` for any `i > 0` (**0-indexed**)
- `1 <= amounti <= 10^4`
- `0 <= k <= 2 * 10^5`

**解決思路:**

此題可以採用prefix sum + binary search策略來解決。

- 先將水果資訊做預處理（前綴和、位置列表），以利後續高效查詢區間總和。

- 解答一定是存在於下列兩種走法的其中一種：
    1. 先往左再往右。
    2. 先往右再往左。

- 因此，對每種情況，我們都去計算能到達的最遠點，過程中用binary search找出區間端點，進而查詢這段區間內的總水果數量。