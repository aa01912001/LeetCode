題號: 3005. Count Elements With Maximum Frequency

難度: Easy

## 問題描述
You are given an array `nums` consisting of positive integers.

Return the **total frequencies** of elements in `nums` such that those elements all have the **maximum** frequency.

The **frequency** of an element is the number of occurrences of that element in the array.

**Example 1:**
```
Input: nums = [1,2,2,3,1,4]
Output: 4
Explanation: The elements 1 and 2 have a frequency of 2 which is the maximum frequency in the array.
So the number of elements in the array with maximum frequency is 4.
```

**Constraints:**

- `1 <= nums.length <= 100`
- `1 <= nums[i] <= 100`


**解決思路:**

計算所有元素的出現個數後，加總那些最大頻率的個數即可。