題號: 632. Smallest Range Covering Elements from K Lists
難度: Hard

## 問題描述

You have `k` lists of sorted integers in **non-decreasing order**. Find the **smallest** range that includes at least one number from each of the k lists.

We define the range `[a, b]` is smaller than range `[c, d]` if `b - a < d - c` **or** `a < c` if `b - a == d - c`.

**Example 1:**
```
Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
Output: [20,24]
Explanation: 
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].
```
**Constraints:**

- `nums.length == k`
- `1 <= k <= 3500`
- `1 <= nums[i].length <= 50`
- `-10^5 <= nums[i][j] <= 10^5`
- `nums[i]` is sorted in **non-decreasing** order.

---
## 解決思路

此題我們需要去尋找盡可能小的範圍，又每個list已經是排序好的，因此，我們可以將每個list各取一個最後面的元素`{a1, a2, ... , an}`並取其中最小與最大值`{a_min, a_max}`來與目前解答比較，若範圍較小則更新解答，之後假設其中最大值為`ai`，我們就去更換`ai`為第`i`個list中次大的值並繼續進行比較，如此我們即可得到一組最佳解。

程式中，我們使用`priority_queue<vector<int>>`來記錄每個list的當前最大值與其位於哪個list(`i`)與哪個index(`j`)，如此我們就能取出`{a1, a2, ... , an}`中的最大值。
