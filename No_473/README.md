題號: 473. Matchsticks to Square
難度: Medium

## 問題描述
You are given an integer array `matchsticks` where `matchsticks[i]` is the length of the `ith` matchstick. You want to use **all the matchsticks** to make one square. You **should not break** any stick, but you can link them up, and each matchstick must be used **exactly one time**.

Return `true` if you can make this square and `false` otherwise.

**Example 1:**
![](https://hackmd.io/_uploads/BypGsKTBh.png)
```
Input: matchsticks = [1,1,2,2,2]
Output: true
Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.
```
**Constraints:**

- `1 <= matchsticks.length <= 15`
- `1 <= matchsticks[i] <= 10^8`

## 解決思路
此題相當於將`nums`劃分為四個總和相同的群組，因此我們可以利用backtracking的方式嘗試將每個數字放到個別個數組中。在程式中，一但某個群組加上當前數字的總和超過`target`(`nums`的總和除以4)，我們就去掉此遞迴分支。

另外，我們首先將`nums`做遞減排序，以便優先將不合法的組合分支去掉，減少遞迴呼叫。

