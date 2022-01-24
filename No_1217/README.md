題號: 1217. Minimum Cost to Move Chips to The Same Position
難度: Easy

## 問題描述

We have `n` chips, where the position of the `ith` chip is `position[i]`.

We need to move all the chips to **the same position**. In one step, we can change the position of the `ith` chip from `position[i]` to:

- `position[i] + 2 or position[i] - 2` with `cost = 0`.
- `position[i] + 1` or `position[i] - 1` with `cost = 1`.

Return the minimum cost needed to move all the chips to the same position.

**Example 1:**
![image alt](https://assets.leetcode.com/uploads/2020/08/15/chips_e1.jpg)
```
Input: position = [1,2,3]
Output: 1
Explanation: First step: Move the chip at position 3 to position 1 with cost = 0.
Second step: Move the chip at position 2 to position 1 with cost = 1.
Total cost is 1.
```


**Constraints:**

- `1 <= position.length <= 100`
- `1 <= position[i] <= 10^9`

---
## 解決思路

此題我們我們可以計算`position`中奇偶數的各數，之後分為兩種情況：

1. 奇數的個數比偶數多：
    我們將所有Chip移至奇數位置上，因此所有原本於偶數位置的Chip會使成本加1
    
2. 偶數的個數比奇數多：
    我們將所有Chip移至偶數位置上，因此所有原本於奇數位置的Chip會使成本加1