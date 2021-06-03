題號: 1561. Maximum Number of Coins You Can Get

難度: Medium

## 問題描述

There are 3n piles of coins of varying size, you and your friends will take piles of coins as follows:

- In each step, you will choose **any** 3 piles of coins (not necessarily consecutive).
- Of your choice, Alice will pick the pile with the maximum number of coins.
- You will pick the next pile with maximum number of coins.
- Your friend Bob will pick the last pile.
- Repeat until there are no more piles of coins.


Given an array of integers `piles` where `piles[i]` is the number of coins in the `ith` pile.

Return the maximum number of coins which you can have.

Example 1:


```
Input: piles = [2,4,1,2,7,8]
Output: 9
Explanation: Choose the triplet (2, 7, 8), Alice Pick the pile with 8 coins, you the pile with 7 coins and Bob the last one.
Choose the triplet (1, 2, 4), Alice Pick the pile with 4 coins, you the pile with 2 coins and Bob the last one.
The maximum number of coins which you can have are: 7 + 2 = 9.
On the other hand if we choose this arrangement (1, 2, 8), (2, 4, 7) you only get 2 + 4 = 6 coins which is not optimal.
```

Constraints:

- `3 <= piles.length <= 10^5`
- `piles.length % 3 == 0`
- `1 <= piles[i] <= 10^4`

---
## 解決思路

此題可以發現Alice每次都會把最多的先選走，而我們的最佳解就是把第二多的先拿走，為了讓我們盡量拿到多的coins，我們每次挑選piles時，會選出當前piles中最大的兩推與最小的一堆使得Alice拿走最大的，Bob拿走最小的。

因此我們可以將`piles`先做sort後，再依照上述步驟將每次的第二多堆拿走。