題號: 1423. Maximum Points You Can Obtain from Cards
難度: Medium

## 問題描述

There are several cards **arranged in a row**, and each card has an associated number of points. The points are given in the integer array `cardPoints`.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly `k` cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array `cardPoints` and the integer `k`, return the maximum score you can obtain.

```
Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.
```

**Constraints:**

- `1 <= cardPoints.length <= 10^5`
- `1 <= cardPoints[i] <= 10^4`
- `1 <= k <= cardPoints.length`

---
## 解決思路

此題我們可以先對`cardPoints`做prefix sum，之後透過觀察我們可以發現答案會出自下列組合中的某一個取法:

(0, k)
(1, k-1)
.
.
.
(i, j)
.
.
.
(k-1, 1)
(k, 0)

其中(i, j)代表從最左邊取i個，最右邊取j個，且i+j==k，因此透過先前執行的prefix sum我們就能夠快速上述任一組合之point總和，而我們最後只需要返回最大的總和數即可。

