題號: 2439. Minimize Maximum of Array
難度: Medium

## 問題描述
You are given a **0-indexed** array `nums` comprising of n non-negative integers.

In one operation, you must:

- Choose an integer `i` such that `1 <= i < n` and `nums[i] > 0`.
- Decrease `nums[i]` by 1.
- Increase `nums[i - 1]` by 1.

**Example 1:**
```
Input: nums = [3,7,1,6]
Output: 5
Explanation:
One set of optimal operations is as follows:
1. Choose i = 1, and nums becomes [4,6,1,6].
2. Choose i = 3, and nums becomes [4,6,2,5].
3. Choose i = 1, and nums becomes [5,5,2,5].
The maximum integer of nums is 5. It can be shown that the maximum number cannot be less than 5.
Therefore, we return 5.
```

**Constraints:**

- `n == nums.length`
- `2 <= n <= 10^5`
- `0 <= nums[i] <= 10^9`


**解決思路:**
此題我們採用binary search的方式來猜測某個數字(`target`)是否能滿足，也就是`nums`能夠在做了數次operations後，使得所有的值皆小於等於`target`。

對於長度為`n`的數組`nums`來說，檢測`target`是否滿足的方式如下:

我們從`nums[n-1]`到`nums[0]`一一比較是否大於`target`:

- 若`nums[i] <= target`，則不需要做任何事。
- 若`nums[i] > target`, 我們必須透過operation使`nums[i]`降低至`target`，並且我們需要將`nums[i] - target`加到`nums[i-1]`作為代價。

迭代完後，我們只需要判斷`nums[0]`是否小於等於`target`即可。
