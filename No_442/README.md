題號: 442. Find All Duplicates in an Array

難度: Medium

## 問題描述
Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear **twice** and others appear **once**.

Find all the elements that appear **twice** in this array.

Could you do it without extra space and in O(n) runtime?


Example 1:

```
Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]
```

---
## 解決思路
此題我們需要用負號標記法來找出出現兩次的數，在遍歷的過程中，我們若發現`nums[value - 1] < 0, 其中value = abs(nums[i])`，則代表該value已經出現過，否則將該value所對應之位置中的值加上負號。