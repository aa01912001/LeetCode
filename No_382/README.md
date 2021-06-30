題號: 382. Linked List Random Node

難度: Medium

## 問題描述

Given a singly linked list, return a random node's value from the linked list. Each node must have the **same probability** of being chosen.

**Example 1:**
![image alt](https://i.imgur.com/MFUt59J.png)


```
Input
["Solution", "getRandom", "getRandom", "getRandom", "getRandom", "getRandom"]
[[[1, 2, 3]], [], [], [], [], []]
Output
[null, 1, 3, 2, 2, 3]

Explanation
Solution solution = new Solution([1, 2, 3]);
solution.getRandom(); // return 1
solution.getRandom(); // return 3
solution.getRandom(); // return 2
solution.getRandom(); // return 2
solution.getRandom(); // return 3
// getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.
```

**Constraints:**

- The number of nodes in the linked list will be in the range `[1, 10^4]`.
- `-10^4 <= Node.val <= 10^4`
- At most 10^4 calls will be made to `getRandom`.


---
## 解決思路

此題只需要將linked list中的元素放入一個`vector<int>`中，同時計算長度`n`。之後只需要random出一個介於`(0, n]`之間的數後，返回vector對應的索引值即可。

