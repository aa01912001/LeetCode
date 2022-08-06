題號: 1035. Uncrossed Lines
難度: Medium

## 問題描述

You are given two integer arrays `nums1` and `nums2`. We write the integers of `nums1` and `nums2` (in the order they are given) on two separate horizontal lines.

We may draw connecting lines: a straight line connecting two numbers `nums1[i]` and `nums2[j]` such that:

- `nums1[i] == nums2[j]`, and
- the line we draw does not intersect any other connecting (non-horizontal) line.

Note that a connecting line cannot intersect even at the endpoints (i.e., each number can only belong to one connecting line).

Return the maximum number of connecting lines we can draw in this way.

**Example 1:**
![image alt](https://assets.leetcode.com/uploads/2019/04/26/142.png)
```
Input: nums1 = [1,4,2], nums2 = [1,2,4]
Output: 2
Explanation: We can draw 2 uncrossed lines as in the diagram.
We cannot draw 3 uncrossed lines, because the line from nums1[1] = 4 to nums2[2] = 4 will intersect the line from nums1[2]=2 to nums2[1]=2.
```
**Constraints:**

- `1 <= nums1.length, nums2.length <= 500`
- `1 <= nums1[i], nums2[j] <= 2000`

---
## 解決思路

此題我們可利用DP策略如同解LCS問題的方式來解決。

程式中`dp[i+1][j+1]`(邊界為0)，代表著`num1[i]`與`nums[j]`之解，而我們DP的狀態轉移式如下：

 - `dp[i+1][j+1] = 1+dp[i][j], if nums1[i] == nums2[j]`
 - `dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1])`

如此最後我們只要返回dp最後一個元素即為正確答案。