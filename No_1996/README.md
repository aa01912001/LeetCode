題號: 1996. The Number of Weak Characters in the Game

難度: Medium

## 問題描述
You are playing a game that contains multiple characters, and each of the characters has two main properties: **attack** and **defense**.  
You are given a 2D integer array `properties` where `properties[i] = [attackᵢ, defenseᵢ]` represents the properties of the *i*ᵗʰ character in the game.

A character is said to be **weak** if any other character has both attack and defense levels **strictly greater** than this character's attack and defense levels.  
More formally, a character *i* is said to be weak if there exists another character *j* where  
`attackⱼ > attackᵢ` **and** `defenseⱼ > defenseᵢ`.

Return the number of **weak characters**.

**Example 1:**
```
Input: properties = [[5,5],[6,3],[3,6]]
Output: 0
Explanation: No character has strictly greater attack and defense than the other.
```

**Constraints:**

- `2 <= properties.length <= 10^5`
- `properties[i].length == 2`
- `1 <= attackᵢ, defenseᵢ <= 10^5`

**解決思路:**

我們可以針對attack對`properties`做遞增排序，之後我們建構出一個`right_max_defense`，其中`right_max_defense[i]`代表`properties[i] ~ properties[n-1]`的最大防禦值。

有了上述前置作業後，我們針對排序後的`properties`從頭開始遍歷，並且針對每個`properties[i]`有如下操作:

1. 使用binary search找出從`properties[i+1] ~ properties[n-1]`中第一個attack > 當前attack的索引位置`j`。

2. 如果當前defense小於`right_max_defense[j]`的話，則代表後面必定存在一個property使得`properties[i]`為weak，因此我們將解答值加上1。