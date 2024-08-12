題號: 3158. Find the XOR of Numbers Which Appear Twice
難度: Easy

## 問題描述
You are given an array `nums`, where each number in the array appears **either** once or twice.

Return the bitwise `XOR` of all the numbers that appear twice in the array, or 0 if no number appears twice.

**Example 1:**
```
Input: nums = [1,2,1,3]

Output: 1

Explanation:

The only number that appears twice in nums is 1.
```

**Constraints:**

- `1 <= nums.length <= 50`
- `1 <= nums[i] <= 50`
- Each number in `nums` appears either once or twice.

**解決思路:**
此題只需要用hash table紀錄每個數字的個數，再將那些個數為2的數全部XOR起來即可。