題號: 1688. Count of Matches in Tournament

難度: Easy

## 問題描述
You are given an integer `n`, the number of teams in a tournament that has strange rules:

- If the current number of teams is **even**, each team gets paired with another team. A total of `n / 2 `matches are played, and `n / 2` teams advance to the next round.

- If the current number of teams is **odd**, one team randomly advances in the tournament, and the rest gets paired. A total of `(n - 1) / 2` matches are played, and `(n - 1) / 2 + 1 `teams advance to the next round.

Return the number of matches played in the tournament until a winner is decided.

Example 1:
```
Input: n = 7
Output: 6
Explanation: Details of the tournament: 
- 1st Round: Teams = 7, Matches = 3, and 4 teams advance.
- 2nd Round: Teams = 4, Matches = 2, and 2 teams advance.
- 3rd Round: Teams = 2, Matches = 1, and 1 team is declared the winner.
Total number of matches = 3 + 2 + 1 = 6.
```
Constraints:

- `1 <= n <= 200`

---
## 解決思路
此題直接用遞迴去解即可，終止條件為當n等於1時則返回0(因為不需比賽)，否則由n為奇、偶數狀況分別處理。