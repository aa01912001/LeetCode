題號: 1441. Build an Array With Stack Operations

難度: Easy

## 問題描述

Given an array `target` and an integer `n`. In each iteration, you will read a number from  `list = {1,2,3..., n}`.

Build the `target` array using the following operations:

- **Push:** Read a new element from the beginning `list`, and push it in the array.
- **Pop:** delete the last element of the array.
- If the target array is already built, stop reading more elements.

Return the operations to build the target array. You are guaranteed that the answer is unique.

**Example 1:**

```
Input: target = [1,3], n = 3
Output: ["Push","Push","Pop","Push"]
Explanation: 
Read number 1 and automatically push in the array -> [1]
Read number 2 and automatically push in the array then Pop it -> [1]
Read number 3 and automatically push in the array -> [1,3]
```


**Constraints:**

- `1 <= target.length <= 100`
- `1 <= target[i] <= n`
- `1 <= n <= 100`
- `target` is strictly increasing.


---
## 解決思路

此題只要計算`target`中相鄰兩數的差值，並插入連續的`Push`、`Pop`數量即可。
