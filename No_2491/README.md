題號: 2491. Divide Players Into Teams of Equal Skill
難度: Medium

## 問題描述
You are given a positive integer array `skill` of **even** length `n` where `skill[i]` denotes the skill of the `ith` player. Divide the players into `n / 2` teams of size `2` such that the total skill of each team is **equal**.

The **chemistry** of a team is equal to the **product** of the skills of the players on that team.

Return the sum of the **chemistry** of all the teams, or return -1 if there is no way to divide the players into teams such that the total skill of each team is equal.

**Example 1:**
```
Input: skill = [3,2,5,1,3,4]
Output: 22
Explanation: 
Divide the players into the following teams: (1, 5), (2, 4), (3, 3), where each team has a total skill of 6.
The sum of the chemistry of all the teams is: 1 * 5 + 2 * 4 + 3 * 3 = 5 + 8 + 9 = 22.
```

**Constraints:**

- `2 <= skill.length <= 105`
- `skill.length` is even.
- `1 <= skill[i] <= 1000`

**解決思路:**
由於題目說每個組別的數字總和是相同的，所以我們可以很容易找出該數為:
`target = sum(skill) / (len(skill) / 2)`

之後我們準備一個hash map，從頭開始遍歷每個`skill`中的數字`num`。

若`gap = taget - num`存在於map中，我們則取出`gap`，並將解答加上`num * gap`，否則我們將map中的`num`個數加1。

最後我們只需要判斷map是否為空，即可知道是不是每個數字皆有被分配到組別。
