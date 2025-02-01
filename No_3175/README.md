題號: 3175. Find The First Player to win K Games in a Row
難度: Medium

## 問題描述
A competition consists of `n` players numbered from `0` to `n - 1`.

You are given an integer array `skills` of size `n` and a **positive** integer `k`, where `skills[i]` is the skill level of player `i`. All integers in `skills` are **unique**.

All players are standing in a queue in order from player `0` to player `n - 1`.

The competition process is as follows:

- The first two players in the queue play a game, and the player with the higher skill level wins.
- After the game, the winner stays at the beginning of the queue, and the loser goes to the end of it.

The winner of the competition is the **first** player who wins `k` games **in a row**.

Return the initial index of the winning player.

**Example 1:**
```
Input: skills = [4,2,6,3,9], k = 2

Output: 2

Explanation:

Initially, the queue of players is [0,1,2,3,4]. The following process happens:

- Players 0 and 1 play a game, since the skill of player 0 is higher than that of player 1, player 0 wins. The resulting queue is [0,2,3,4,1].
- Players 0 and 2 play a game, since the skill of player 2 is higher than that of player 0, player 2 wins. The resulting queue is [2,3,4,1,0].
- Players 2 and 3 play a game, since the skill of player 2 is higher than that of player 3, player 2 wins. The resulting queue is [2,4,1,0,3].

Player 2 won k = 2 games in a row, so the winner is player 2.

```

**Constraints:**

- `n == skills.length`
- `2 <= n <= 105`
- `1 <= k <= 109`
- `1 <= skills[i] <= 106`
- All integers in `skills` are unique.

**解決思路:**
此題我們透過觀察可以知道，當輪到`skills`中最大的數在前方時一定可以滿足連續`k`次的勝利。但在輪到此最大數之前，可能也會有某個數`skills[i]`在到達下一個比它大的數之間有超過`k-1`個數，也可滿足此條件。

Note: 為何會是需要`k-1`個而不是`k`個呢? 因為對於`skills[i]`要排到第一個的條件就是一定會先贏過其前面的那個數。

因此我們可以從頭遍歷`skills`，並依序對於當前最大數`skills[i]`來記錄其所需剩餘的獲勝次數，一旦其剩餘次數為0，則返回`i`。若遇到大於它的數`skills[j]`，則將當前最大於換為`skills[j]`，並將剩餘次數改為`k-1`。即可。

最後若有成功迭代完`skills`的話，則當前紀錄之最大數必為全局最大數，我們直接返回該數的index即可。

