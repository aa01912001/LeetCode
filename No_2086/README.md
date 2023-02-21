題號: 2086. Minimum Number of Food Buckets to Feed the Hamsters
難度: Medium

## 問題描述
You are given a **0-indexed** string `hamsters` where `hamsters[i]` is either:

- `'H'` indicating that there is a hamster at index `i`, or
- `'.'` indicating that index `i` is empty.

You will add some number of food buckets at the empty indices in order to feed the hamsters. A hamster can be fed if there is at least one food bucket to its left or to its right. More formally, a hamster at index `i` can be fed if you place a food bucket at index `i - 1` **and/or** at index `i + 1`.

Return the minimum number of food buckets you should **place at empty indices** to feed all the hamsters or `-1` if it is impossible to feed all of them.

**Example 1:**
![](https://i.imgur.com/oKHDpCD.png)
```
Input: hamsters = "H..H"
Output: 2
Explanation: We place two food buckets at indices 1 and 2.
It can be shown that if we place only one food bucket, one of the hamsters will not be fed.
```

**Constraints:**

- `1 <= hamsters.length <= 10^5`
- `hamsters[i]` is either `'H'` or `'.'`.

---
## 解決思路
此題我們可以從頭開始遍歷`hamsters`，若當前為`H`，我們則優先檢查其右邊(盡可能讓後面的`H`可以共用)是否為`.`，若是的話我們將解答值加1，並跳過後面兩個字元(不會影響解答值)，否則檢查左邊字元是否為`.`，若是，則解答值加1，否則當前`H`無法被餵食，因此直接返回-1。