題號: 849. Maximize Distance to Closest Person
難度: Medium

## 問題描述
You are given an array representing a row of `seats` where `seats[i] = 1` represents a person sitting in the `ith` seat, and `seats[i] = 0` represents that the `ith` seat is empty **(0-indexed)**.

There is at least one empty seat, and at least one person sitting.

Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized. 

Return that maximum distance to the closest person.

**Example 1:**
![](https://hackmd.io/_uploads/Bkzdpxiw2.png)
```
Input: seats = [1,0,0,0,1,0,1]
Output: 2
Explanation: 
If Alex sits in the second open seat (i.e. seats[2]), then the closest person has distance 2.
If Alex sits in any other open seat, the closest person has distance 1.
Thus, the maximum distance to the closest person is 2.
```
**Constraints:**

- `2 <= seats.length <= 2 * 10^4`
- `seats[i]` is `0` or `1`.
- At least one seat is **empty**.
- At least one seat is **occupied**.

## 解決思路
此題透過觀察我們可以發現，我們只需要考慮兩個相鄰有坐人的位置的中間點即可。

假設index 0、4坐了人，那麼我們只要比較解答`ret = max(ret, (4-0)/2)`即可，因為坐中間一定是最好的策略。

另外我們在程式中也需要考慮坐在最左或最右的情況。