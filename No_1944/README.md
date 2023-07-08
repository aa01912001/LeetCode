題號: 1944. Number of Visible People in a Queue
難度: Hard

## 問題描述
There are `n` people standing in a queue, and they numbered from `0` to `n - 1` in **left to right** order. You are given an array `heights` of **distinct** integers where `heights[i]` represents the height of the `ith` person.

A person can **see** another person to their right in the queue if everybody in between is **shorter** than both of them. More formally, the `ith` person can see the `jth` person if `i < j` and `min(heights[i], heights[j]) > max(heights[i+1], heights[i+2], ..., heights[j-1])`.

Return an array `answer` of length `n` where `answer[i]` is the **number of people** the `ith` person can **see** to their right in the queue.

**Example 1:**
![](https://hackmd.io/_uploads/HyocGrIFh.png)
```
Input: heights = [10,6,8,5,11,9]
Output: [3,1,2,1,1,0]
Explanation:
Person 0 can see person 1, 2, and 4.
Person 1 can see person 2.
Person 2 can see person 3 and 4.
Person 3 can see person 4.
Person 4 can see person 5.
Person 5 can see no one since nobody is to the right of them.
```
**Constraints:**

- `n == heights.length`
- `1 <= n <= 10^5`
- `1 <= heights[i] <= 10^5`
- All the values of `heights` are **unique**.

## 解決思路
此題我們首先準備一個`stack<int> stk`用以儲存index。我們可以知道兩個人若要互相看到，必須在水平線上能夠直視才行。因此我們採用**monotonic stack**的方式將index `i`之前的身高遞減的索引位置進行紀錄。

對於第`i`個人來說，若其身高高於`stk.top()`位置的人(假設為`j`)，代表索引位置`j`的人一定能看見他，因此我們將解答中的位置`j`之解答值加一，並將其從stack中pop中來，繼續以相同方式比較，直到stack為空或stack top位置的人其身高高於位置`i`的人。

每回合的最後，我們需要將stack top位置的解答值加一(若stack不為空的話)後，再將`i`放入stack中。


