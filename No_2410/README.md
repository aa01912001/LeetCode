題號: 2410. Maximum Matching of Players With Trainers

難度: Medium

## 問題描述
You are given a **0-indexed** integer array `players`, where `players[i]` represents the **ability** of the `ith` player. You are also given a 0-indexed integer array `trainers`, where `trainers[j]` represents the training capacity of the `jth` trainer.

The `ith` player can match with the `jth` trainer if the player's ability is **less than or equal to** the trainer's training capacity. Additionally, the `ith` player can be matched with at most one trainer, and the `jth` trainer can be matched with at most one player.

Return the **maximum** number of matchings between `players` and `trainers` that satisfy these conditions.

**Example 1:**
```
Input: players = [4,7,9], trainers = [8,2,5,8]
Output: 2
Explanation:
One of the ways we can form two matchings is as follows:
- players[0] can be matched with trainers[0] since 4 <= 8.
- players[1] can be matched with trainers[3] since 7 <= 8.
It can be proven that 2 is the maximum number of matchings that can be formed.
```

**Constraints:**

- `1 <= players.length, trainers.length <= 10^5`
- `1 <= players[i], trainers[j] <= 10^9`

**解決思路:**

這題基本上就是對於某個`players[i]`，我們盡量找出跟它的差最小且大於等於它的`trainers[j]`配對即可。

因此我們收先對於`players`與`trainers`做sorting，並另用雙指針的方式來比較，若`players[i] <= trainers`我們則將解答值加一並將`i`與`j`向前一步，否則就單純只移動`j`來尋求下一個trainer是否可以滿足此player。