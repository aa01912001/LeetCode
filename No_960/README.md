題號: 960. Delete Columns to Make Sorted III

難度: `Hard`

## 問題描述

You are given an array of **n** strings `strs`, all of the same length.

We may choose any deletion indices, and we delete all the characters in those indices for each string.

For example, if we have  
`strs = ["abcdef", "uvwxyz"]`  
and deletion indices `{0, 2, 3}`,  
then the final array after deletions is `["bef", "vyz"]`.

Suppose we chose a set of deletion indices `answer` such that after deletions,  
the final array has **every string (row) in lexicographic order**  
(i.e.,  
`strs[0][0] <= strs[0][1] <= ... <= strs[0][strs[0].length - 1]`, and  
`strs[1][0] <= strs[1][1] <= ... <= strs[1][strs[1].length - 1]`, and so on).

Return the **minimum possible value of `answer.length`**.

**Example 1:**
```
Input: strs = ["babca","bbazb"]
Output: 3
Explanation: After deleting columns 0, 1, and 4, the final array is strs = ["bc", "az"].
Both these rows are individually in lexicographic order (ie. strs[0][0] <= strs[0][1] and strs[1][0] <= strs[1][1]).
Note that strs[0] > strs[1] - the array strs is not necessarily in lexicographic order.
```
**Constraints:**

- `n == strs.length`
- `1 <= n <= 100`
- `1 <= strs[i].length <= 100`
- `strs[i]` consists of lowercase English letters.




**解決思路:**

此題我們可以利用DP來解決:

`dp[i]`: 代表以column `i`結尾，並能讓所有string (row) 滿足lexicographically sorted的最大可存在column數量。

我們初始化`dp = [1] * num_cols`，因為單獨保留任何一個 column，都一定合法。

之後我們依序針對每個column `c`，都去嘗試所有可能接在它前面的column `prev`，如果每個row的當前column的字元皆大於等於`prev`位置的話，我們就可以更新`dp[c] = max(dp[c], dp[prev] + 1)`

最後我們從dp找出最大可保留column的個數，並用所有column數減去它即為答案。