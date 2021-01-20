題號: 1029. Two City Scheduling

難度: Medium

## 問題描述
A company is planning to interview `2n` people. Given the array `costs` where `costs[i] = [aCost_i, bCost_i]`, the cost of flying the `i_th` person to city `a` is `aCost_i`, and the cost of flying the `i_th` person to city `b` is `bCost_i`.

Return the minimum cost to fly every person to a city such that exactly n people arrive in each city.

Example 1:
```
Input: costs = [[10,20],[30,200],[400,50],[30,20]]
Output: 110
Explanation: 
The first person goes to city A for a cost of 10.
The second person goes to city A for a cost of 30.
The third person goes to city B for a cost of 50.
The fourth person goes to city B for a cost of 20.

The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people interviewing in each city.
```

Constraints:

- `2 * n == costs.length`
- `2 <= costs.length <= 100`
- `costs.length is even.`
- `1 <= aCost_i, bCost_i <= 1000`

---
## 解決思路
此題首先利用greedy的方式將2n個人依照最小的成本分配到城市a或b，之後若發現某個城市中有超過n個人就表示我們需要將一些人調度到另一個城市中。**而選擇的方式則是採用greedy的方式將具有成本差最小的人給調度出去**。在程式中則是用兩個min heap來儲存在兩個城市中每個人的成本差。我們可以直接返回top()最小的成本差並將此值加入到解答中。