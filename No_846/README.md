題號: 846. Hand of Straights

難度: Medium

## 問題描述
Alice has a `hand` of cards, given as an array of integers.

Now she wants to rearrange the cards into groups so that each group is size `W`, and consists of `W` consecutive cards.

Return `true` if and only if she can.

Example 1:

```
Input: hand = [1,2,3,6,2,3,4,7,8], W = 3
Output: true
Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]
```

Constraints:

- `1 <= hand.length <= 10000`
- `0 <= hand[i] <= 10^9`
- `1 <= W <= hand.length`


---
## 解決思路

此題我們可以用map來儲存hand中每個數字出現的次數，首先我們每次選擇每組的首項時先從數字最小的開始挑，之後再遞增數字挑選出該組的元素即可。
