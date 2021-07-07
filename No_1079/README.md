題號: 1079. Letter Tile Possibilities

難度: Medium

## 問題描述

You have `n`  `tiles`, where each tile has one letter `tiles[i]` printed on it.

Return the number of possible non-empty sequences of letters you can make using the letters printed on those `tiles`.

**Example 1:**


```
Input: tiles = "AAB"
Output: 8
Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".
```

**Constraints:**

- `1 <= tiles.length <= 7`
- `tiles` consists of uppercase English letters.


---
## 解決思路

此題我們可以利用recursive的策略找出`tiles`所有的`permutation`，中途再利用`unordered_set<string>`來記錄不一樣的排列字串，最後返回該set的size即可。
