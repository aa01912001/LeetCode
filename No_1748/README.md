題號: 1748. Sum of Unique Elements

難度: Easy

## 問題描述
You are given an integer array `nums`. The unique elements of an array are the elements that appear **exactly once** in the array.

Return the **sum** of all the unique elements of `nums`.


Example 1:

```
Input: nums = [1,2,3,2]
Output: 4
Explanation: The unique elements are [1,3], and the sum is 4.
```

Constraints:


- `1 <= nums.length <= 100`
- `1 <= nums[i] <= 100`

---
## 解決思路
此題只需利用`unordered_map`來記錄`nums`中每個數字出現過的次數後，再把只出現一次的數字加總即可。