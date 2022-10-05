題號: 1647. Minimum Deletions to Make Character Frequencies Unique
難度: Medium

## 問題描述

A string `s` is called **good** if there are no two different characters in `s` that have the same **frequency**.

Given a string `s`, return the **minimum** number of characters you need to delete to make `s` **good**.

The **frequency** of a character in a string is the number of times it appears in the string. For example, in the string `"aab"`, the **frequency** of `'a'` is `2`, while the **frequency** of `'b'` is `1`.

**Example 1:**
```
Input: s = "aaabbbcc"
Output: 2
Explanation: You can delete two 'b's resulting in the good string "aaabcc".
Another way it to delete one 'b' and one 'c' resulting in the good string "aaabbc".
```

**Constraints:**

- `1 <= s.length <= 10^5`
- `s` contains only lowercase English letters.

---
## 解決思路

此題我們首先可以對`s`的每個字元進行頻率計算，並將結果存於長度為26的`vector<int> count`中，之後我們對`count`進行遞增排序，並從尾端向前進行檢查如下：

- `count[i] < count[i+1]`: 代表`count[i]`所代表的字元不需要進行刪減

- `count[i] >= count[i+1]`: 代表`count[i]`所代表的字元要進行刪減，並且刪減的數量為`count[i] - count[i+1] + 1`，表示將`count[i]`之頻率變為`count[i+1]-1`；需特別注意的是，若`count[i+1]`已經為0，我們只需要將`count[i]`降為0即可。

過程中我們只需要將各個`count[i]`所刪減的次數進行加總即為答案。