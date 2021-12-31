題號: 491. Increasing Subsequences
難度: Medium

## 問題描述

Given an integer array `nums`, return all the different possible increasing subsequences of the given array with **at least two elements**. You may return the answer in **any order**.

The given array may contain duplicates, and two equal integers should also be considered a special case of increasing sequence.

 

**Example 1:**
```
Input: nums = [4,6,7,7]
Output: [[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
```


**Constraints:**

- `1 <= nums.length <= 15`
- `-100 <= nums[i] <= 100`

---
## 解決思路

此題可以利用backtraking的方式解決，程式中我們用`vector<int> tmp`來存放`nums[i]`之前合法的**Increasing Subsequences**，一但遇到`nums[i]`之後某個位置其值小於`tmp`最後一個數，代表我們若加入此數進`tmp`會形成不合法的**Increasing Subsequences**，因此我們必須跳過此位置並考慮後續位置，而對於加入後仍形成合法**Increasing Subsequences**的位置，我們要同時考慮將其加入或不加入`tmp`之情況，並繼續進行遞迴。

另外，程式中我們利用`set<vector<int>> hset`的結構將遞迴中所有長度大於等於2以上的`tmp`放入，以避免將重複的**Increasing Subsequences**放入解答中，因此最後只要將`hset`中的所有**Increasing Subsequences**取出並放入vector中即為解答。
