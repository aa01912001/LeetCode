題號: 1498. Number of Subsequences That Satisfy the Given Sum Condition

難度: Medium

## 問題描述
You are given an array of integers `nums` and an integer `target`.

Return the number of **non-empty** subsequences of `nums` such that the sum of the minimum and maximum element on it is less or equal to `target`. Since the answer may be too large, return it modulo `10^9 + 7`.

**Example 1:**
```
Input: nums = [3,5,6,7], target = 9
Output: 4
Explanation: There are 4 subsequences that satisfy the condition.
[3] -> Min value + max value <= target (3 + 3 <= 9)
[3,5] -> (3 + 5 <= 9)
[3,5,6] -> (3 + 6 <= 9)
[3,6] -> (3 + 6 <= 9)
```

**Constraints:**

- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^6`
- `1 <= target <= 10^6`

**解決思路:**

我們不難想出一個合法的subsequence，相當於直接從`nums`的一個子集合，因此我們可以不需要在意`nums`實際的元素順序，而些將`nums`做遞增排序。

對於一個`nums[i]`，我們假設他是合法的子序列中最小的元素，那麼我們可以嘗試找到其對應最大的合法元素`nums[j]`，使得`nums[i] + nums[j] <= target`。

對於`nums[i], nums[i+1], ... , nums[j-1], nums[j]`的範圍，我們知道包含`nums[i]`為最小元素的合法子序列個數為`2^(j-i)`組，因為`nums[i+1], ... ,nums[j]`都有選或不選2種可能性。因此我們的解題路就是針對每個`nums[i]`都去尋找最大可能的合法元素`nums[j]`，並加總包含`nums[i]`為最小元素的合法子序列個數即可。

然而由於`nums`已經被我們排序過，因此可以透過**two pointer**的方式來降低複雜度，其思路如下:

初始化`i = 0`, `j = n - 1`，其中`n`為`nums`長度

如果`nums[i] + nums[j] <= target`，代表`nums[j]`已經是`nums[i]`的最大可能對應值，我們將解答加上`2^(j-i)`後，再`i`右移，針對下一個元素進行尋找。

但若是`nums[i] + nums[j] > target`，代表`nums[j]`太大了無法成為之後所有元素(`nums[i]、nums[i+1]、...、nums[j]`)的合法最大值，因此我們將`j`左移來降低超過`target`的可能性。如此直至`j < i`即可返回解答值。
