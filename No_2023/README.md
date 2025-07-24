題號: 2023. Number of Pairs of Strings With Concatenation Equal to Target

難度: Medium

## 問題描述
Given an array of **digit** strings `nums` and a **digit** string `target`, return the number of pairs of indices `(i, j)` (where `i != j`) such that the **concatenation** of `nums[i] + nums[j]` equals `target`.

**Example 1:**
```
Input: nums = ["777","7","77","77"], target = "7777"
Output: 4
Explanation: Valid pairs are:
- (0, 1): "777" + "7"
- (1, 0): "7" + "777"
- (2, 3): "77" + "77"
- (3, 2): "77" + "77"
```

**Constraints:**

- `2 <= nums.length <= 100`
- `1 <= nums[i].length <= 100`
- `2 <= target.length <= 100`
- `nums[i]` and `target` consist of digits.
- `nums[i]` and `target` do not have leading zeros.

**解決思路:**

我們可以先將nums中的每個元素出現的次數記錄起來存為`freqs`，之後我們從頭開始迭代`nums`，並判斷當前`num`是否為`target`的prefix。

如果是的話我們就另外取出扣掉`num`的postfix字串並將解答值加上`freqs[postfix]`，代表如果我們以`num`為前綴的話一共可以找到`freqs[postfix]`那麼多的其他字串做為後綴。

但我們需要另外判斷如果`num`等於`postfix`的話，代表我們重複將`num`自身作為後綴考慮進解答中了，因此我們需要將解答值扣掉1。