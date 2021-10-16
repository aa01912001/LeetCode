題號: 384. Shuffle an Array

難度: Medium

## 問題描述

Given an integer array `nums`, design an algorithm to randomly shuffle the array. All permutations of the array should be **equally likely** as a result of the shuffling.

Implement the `Solution` class:

- `Solution(int[] nums)` Initializes the object with the integer array `nums`.
- `int[] reset()` Resets the array to its original configuration and returns it.
- `int[] shuffle()` Returns a random shuffling of the array.

**Example 1:**

```
Input
["Solution", "shuffle", "reset", "shuffle"]
[[[1, 2, 3]], [], [], []]
Output
[null, [3, 1, 2], [1, 2, 3], [1, 3, 2]]

Explanation
Solution solution = new Solution([1, 2, 3]);
solution.shuffle();    // Shuffle the array [1,2,3] and return its result.
                       // Any permutation of [1,2,3] must be equally likely to be returned.
                       // Example: return [3, 1, 2]
solution.reset();      // Resets the array back to its original configuration [1,2,3]. Return [1, 2, 3]
solution.shuffle();    // Returns the random shuffling of array [1,2,3]. Example: return [1, 3, 2]
```

**Constraints:**

- `1 <= nums.length <= 200`
- `-10^6 <= nums[i] <= 10^6`
- All the elements of `nums` are **unique**.
- At most `5 * 10^4` calls **in total** will be made to `reset` and `shuffle`.

---
## 解決思路

此題一開始要先記錄最原本的`nums`，以便後續做`reset`時可以返回。而對於`shuffle`操作，我們只會要對array中的每一個值隨機賦予一個新的索引值即可。



