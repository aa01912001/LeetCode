題號: 1354. Construct Target Array With Multiple Sums
難度: Hard

## 問題描述
You are given an array `target` of n integers. From a starting array `arr` consisting of `n` 1's, you may perform the following procedure :


- let `x` be the sum of all elements currently in your array.
- choose index `i`, such that `0 <= i < n` and set the value of `arr` at index `i` to `x`.
- You may repeat this procedure as many times as needed.

Return `true` if it is possible to construct the `target` array from `arr`, otherwise, return `false`.

**Example 1:**
```
Input: target = [9,3,5]
Output: true
Explanation: Start with arr = [1, 1, 1] 
[1, 1, 1], sum = 3 choose index 1
[1, 3, 1], sum = 5 choose index 2
[1, 3, 5], sum = 9 choose index 0
[9, 3, 5] Done
```
**Constraints:**

- `n == target.length`
- `1 <= n <= 5 * 10^4`
- `1 <= target[i] <= 10^9`

## 解決思路
我們可以知道當前最大的數，一定是最後一次疊加上去造成的結果，因此我們只需要利用max heap將`target`中的所有數放入後，並在每一回合時將最大的數取出(假設為t)並減去當前總和與t的差值後，在將其存回heap中。我們重複此操作直至所有數字都變成1即可。