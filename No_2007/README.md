題號: 2007. Find Original Array From Doubled Array
難度: Medium

## 問題描述
An integer array `original` is transformed into a **doubled** array `changed` by appending **twice the value** of every element in `original`, and then randomly **shuffling** the resulting array.

Given an array `changed`, return `original` if `changed` is a **doubled** array. If `changed` is not a **doubled** array, return an empty array. The elements in `original` may be returned in **any** order.

**Example 1:**
```
Input: changed = [1,3,4,2,6,8]
Output: [1,3,4]
Explanation: One possible original array could be [1,3,4]:
- Twice the value of 1 is 1 * 2 = 2.
- Twice the value of 3 is 3 * 2 = 6.
- Twice the value of 4 is 4 * 2 = 8.
Other original arrays could be [4,3,1] or [3,1,4].
```

**Constraints:**

- `1 <= changed.length <= 10^5`
- `0 <= changed[i] <= 10^5`

## 解決思路
此題我們只需要利用hash map記錄所有元素的個數，再對`changed`做sort。

我們知道`changed`中的最大值(假設為`num`)，一定是由`num/2`而來，因此我們可以將`num/2`放入解答陣列中，並將map中的`num`與`num/2`刪除，繼續尋找下一回合之`changed`最大值。