題號: 2498. Frog Jump II
難度: Medium

## 問題描述
You are given a **0-indexed** integer array `stones` sorted in **strictly increasing order** representing the positions of stones in a river.

A frog, initially on the first stone, wants to travel to the last stone and then return to the first stone. However, it can jump to any stone **at most once**.

The **length** of a jump is the absolute difference between the position of the stone the frog is currently on and the position of the stone to which the frog jumps.

- More formally, if the frog is at `stones[i]` and is jumping to `stones[j]`, the length of the jump is `|stones[i] - stones[j]|`.

The **cost** of a path is the **maximum length of a jump** among all jumps in the path.

Return the **minimum** cost of a path for the frog.

**Example 1:**
![](https://i.imgur.com/T6NHSJT.png)
```
Input: stones = [0,2,5,6,7]
Output: 5
Explanation: The above figure represents one of the optimal paths the frog can take.
The cost of this path is 5, which is the maximum length of a jump.
Since it is not possible to achieve a cost of less than 5, we return it.
```

**Constraints:**

- `2 <= stones.length <= 10^5`
- `0 <= stones[i] <= 10^9`
- `stones[0] == 0`
- `stones` is sorted in a strictly increasing order.

---
## 解決思路
此題我們我們可以試想連續三顆石頭的位置為:

p1, p2, p3

若今天任兩顆相鄰的石頭路徑被青蛙採用會導致其回程時有更長的路徑，因此最佳策略為去程與回程時皆間隔跳。故我們只需要找出最長間隔距離即可。
