題號: 1432. Max Difference You Can Get From Changing an Integer

難度: Medium

## 問題描述
You are given an integer `num`. You will apply the following steps to `num` two separate times:

- Pick a digit `x (0 <= x <= 9)`.
- Pick another digit `y (0 <= y <= 9)`. Note `y` can be equal to `x`.
- Replace all the occurrences of `x` in the decimal representation of `num` by `y`.

Let `a` and `b` be the two results from applying the operation to `num` independently.

Return the max difference between `a` and `b`.

Note that neither `a` nor `b` may have any leading zeros, and must not be 0.

**Example 1:**
```
Input: num = 555
Output: 888
Explanation: The first time pick x = 5 and y = 9 and store the new integer in a.
The second time pick x = 5 and y = 1 and store the new integer in b.
We have now a = 999 and b = 111 and max difference = 888
```

**Constraints:**

- `1 <= num <= 10^8`


**解決思路:**

此題對於`a`來說，我們需要盡可能的最大化此數，因此我們可以從頭開始遍歷尋找非'9'的字元，並將其字元通通轉換成'9'。

而對於`b`來說，則需要盡可能的最小化，因此可以同樣從頭開始遍歷。如果第一個字元不為'1'，我們直接將這個字元轉化成'1'即可，否則對於index 1以後的字元我們我們需要尋找非'0'且不等於index 0的字元的數字，並將其轉成'0'。

最後將`a`與`b`相減即可。