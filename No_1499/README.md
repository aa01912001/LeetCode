題號: 1499. Max Value of Equation
難度: Hard

## 問題描述
You are given an array `points` containing the coordinates of points on a 2D plane, sorted by the x-values, where `points[i] = [xi, yi]` such that `xi < xj` for all `1 <= i < j <= points.length`. You are also given an integer `k`.

Return the maximum value of the equation `yi + yj + |xi - xj|` where `|xi - xj| <= k` and `1 <= i < j <= points.length`.

It is guaranteed that there exists at least one pair of points that satisfy the constraint `|xi - xj| <= k`.

**Example 1:**
```
Input: points = [[1,3],[2,0],[5,10],[6,-10]], k = 1
Output: 4
Explanation: The first two points satisfy the condition |xi - xj| <= 1 and if we calculate the equation we get 3 + 0 + |1 - 2| = 4. Third and fourth points also satisfy the condition and give a value of 10 + -10 + |5 - 6| = 1.
No other pairs satisfy the condition, so we return the max of 4 and 1.
```
**Constraints:**

- `2 <= points.length <= 10^5`
- `points[i].length == 2`
- `-10^8 <= xi, yi <= 10^8`
- `0 <= k <= 2 * 10^8`
- `xi < xj` for all `1 <= i < j <= points.length`
- `xi` form a strictly increasing sequence.

## 解決思路
此題我們可以利用`deque<vector<int>> dq`來進行monotonic數值的儲存，其中queue的前端保存了當前最大優勢的point。

這裡的最大優勢是指若當前的point(假設為`points[i]`)其x與queue前端point(假設為`dq.front()`)的x距離不超過`k`，那麼`points[i]`與`dq.front()`計算出來的值一定大於其他queue中的points。

在每回合中:
1. 我們首先將所有queue前端與`points[i]`距離大於`k`的節點取出拋棄。
2. 以`points[i]`跟`dq.front()`公式之值更新當前解答。
3. 不斷跟queue尾端元素(`dq.back()`)比較，判斷`points[i]`是否比`dq.back()`較有優勢，若是的話則將尾端元素取出拋棄。而我們比較的方式是比較`points[i][1] - dq.back()[1]`是否大於等於`points[i][0] - dq.back()[0]`，意義為當前節點是否可以藉由y值的差距來彌補或勝過x值的弱勢，若成立的話代表後續節點跟`points[i]`以公式計算出來的值一定較當前queue尾端元素來的大。
4. 將`points[i]`放入queue尾端。
