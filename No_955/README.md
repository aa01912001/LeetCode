題號: 955. Delete Columns to Make Sorted II


難度: `Medium`

## 問題描述

You are given an array of **n** strings `strs`, all of the same length.

We may choose any deletion indices, and we delete all the characters in those indices for each string.

For example, if we have  
`strs = ["abcdef", "uvwxyz"]`  
and deletion indices `{0, 2, 3}`, then the final array after deletions is  
`["bef", "vyz"]`.

Suppose we chose a set of deletion indices `answer` such that after deletions, the final array has its elements in **lexicographic order** (i.e.,  
`strs[0] <= strs[1] <= strs[2] <= ... <= strs[n - 1]`).

Return the **minimum possible value** of `answer.length`.


**Example 1:**
```
Input: strs = ["ca","bb","ac"]
Output: 1
Explanation: 
After deleting the first column, strs = ["a", "b", "c"].
Now strs is in lexicographic order (ie. strs[0] <= strs[1] <= strs[2]).
We require at least 1 deletion since initially strs was not in lexicographic order, so the answer is 1.
```
**Constraints:**

- `n == strs.length`
- `1 <= n <= 100`
- `1 <= strs[i].length <= 100`
- `strs[i]` consists of lowercase English letters.



**解決思路:**

此題我們必須一一比較每個字串的某個column是否合法。

我們維護一個狀態陣列：
- `sorted_pair = [False] * rows`
    - 表示在之前某一個 column 中，已經確定 `strs[i-1] < strs[i]`
    - 一旦這個關係成立，後續的 column 就不需要再比較這一對字串


每一個 column 的處理流程:
1. 逐 row 比較尚未確定順序的字串對
    - 只比較 `sorted_pair[i] == False` 的 
2. 如果出現 `strs[i][col] < strs[i-1][col]`，代表這個column必須刪除

3. 如果出現`strs[i][col] > strs[i-1][col]`
    - 代表在此 column 中，成功確定了`strs[i-1] < strs[i]`，將這個結果暫存於 `newly_sorted[i]`

4. 只要該column回合結束且沒有發生需要delete這個column的話，我們就必須更新`sorted_pair[i] = sorted_pair[i] |= newly_sorted[i]`

