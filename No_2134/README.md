題號: 2134. Minimum Swaps to Group All 1's Together II
難度: Medium

## 問題描述
A **swap** is defined as taking two **distinct** positions in an array and swapping the values in them.

A **circular** array is defined as an array where we consider the **first** element and the **last** element to be **adjacent**.

Given a **binary circular** array `nums`, return the minimum number of swaps required to group all `1`'s present in the array together at **any location**.

**Example 1:**
```
Input: nums = [0,1,1,1,0,0,1,1,0]
Output: 2
Explanation: Here are a few of the ways to group all the 1's together:
[1,1,1,0,0,0,0,1,1] using 2 swaps (using the circular property of the array).
[1,1,1,1,1,0,0,0,0] using 2 swaps.
There is no way to group all 1's together with 0 or 1 swaps.
Thus, the minimum number of swaps required is 2.
```

**Constraints:**

- `1 <= nums.length <= 10^5`
- `nums[i]` is either `0` or `1`.

## 解決思路
此題我們採用sliding window的方式解決。

首先我們計算window的寬度`width`為`nums`中所有1的個數。

假設當前window內0的個數為`zeros`，我們可以知道若要將所有的1放入此window中，則需要`zeros`次的swap，因此我們可以不斷移動我們的window並同時更新解答值為最小的當前`zeros`。

