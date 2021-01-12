題號: 881. Boats to Save People

難度: Medium

## 問題描述
The `i`-th person has weight `people[i]`, and each boat can carry a maximum weight of `limit`.

Each boat carries at most 2 people at the same time, provided the sum of the weight of those people is at most `limit`.

Return the minimum number of boats to carry every given person.  (It is guaranteed each person can be carried by a boat.)

 

Example 1:
```
Input: people = [3,2,2,1], limit = 3
Output: 3
Explanation: 3 boats (1, 2), (2) and (3)
```



Note:

- `1 <= people.length <= 50000`
- `1 <= people[i] <= limit <= 30000`


---
## 解決思路
此題先people做排序，再用i、j作為指向最小和最大的index，我們可以知道每一艘船承載的量越接近limit越好，所以每一趟都載people[j] + people[i]，若people[j] + people[i]大於limit則表示people[j]要單獨去載。載完後就將j - 1、i + 1(要看有沒有載小的)。如此即可找出最小數量的船。
